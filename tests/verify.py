"""Exercise terminal workflows using only temporary builds and synthetic media."""
from pathlib import Path
import subprocess,tempfile,shutil,os
root=Path(__file__).resolve().parents[1]
with tempfile.TemporaryDirectory(prefix='photo-catalog-check-') as tmp:
    tmp=Path(tmp);exe=tmp/('catalog.exe' if os.name=='nt' else 'catalog')
    subprocess.run(['g++','-std=c++11',*[str(p) for p in root.glob('*.cc')],'-o',str(exe)],check=True)
    def check(input,expected,cwd=root):
        r=subprocess.run([str(exe)],cwd=cwd,input=input,text=True,capture_output=True,timeout=5)
        assert r.returncode==0, r.stderr
        for text in expected:assert text in r.stdout, text
    check('1\nTrip\nNature\n8\nnature\n12\n1\n4\n1\n0\n',['Photo #2:','Photo title: Mountain','Good-bye!'])
    check('7\n2023 4 1\n2023 4 3\n10\n0\n',['Photo list size: 3'])
    check('9\nnature\n2023 4 1\n2023 4 3\n10\n0\n',['Photo list size: 2'])
    check('1\nKeep\nAlbum\n2\n0\n3\n0\n',['Album: Keep'])
    check('1\nRemove\nAlbum\n2\n1\n3\n0\n',['Printing all Albums:','Good-bye!'])
    check('', ['Good-bye!'])
    check('invalid\n', ['Good-bye!'])
    media=tmp/'media';media.mkdir();(media/'phototitles.txt').write_text('Missing\n')
    (media/'photos.txt').write_text('Broken\nnature\n2023 4 2\nunterminated\n')
    check('5\n0\n',['Good-bye!'],tmp)
print('PASS: album/search/cancel/delete/EOF/malformed-media workflows')
