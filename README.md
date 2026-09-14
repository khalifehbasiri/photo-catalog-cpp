# Photo catalog in C++

A terminal catalog for ASCII artwork, with albums and category/date searches.

## Features

- Load a small text-file catalog and display its artwork.
- Create, browse and delete albums.
- Filter photos by category, date range, or both.
- Add the current search results to an album.
- Demonstrate a templated collection, factories and polymorphic search criteria.

## Build and run

Requires a C++11 compiler. From the repository root:

```sh
g++ -std=c++11 *.cc -o photo-catalog
./photo-catalog
```

On Windows run `photo-catalog.exe`. GNU Make (`make run`) and CMake are also supported. Run from the root so `media/` resolves correctly. Choose 1 to create an album, 8 to search for `nature`, 12 to add results, and 4 to display the album. Choose 0 at the main menu to exit. Titles and descriptions currently accept one whitespace-delimited word.

## Repository contents

| Files | Purpose |
| --- | --- |
| AlbumCreator, View | Menu flow and terminal presentation |
| PhotoGram, Album, Photo | Catalog and album model |
| Criteria, Date | Category and date comparisons |
| MediaFactory | Read text records and create objects |
| Array.h | Fixed-capacity templated collection |
| media/ | Three synthetic ASCII fixtures; no personal photos |

Records contain a title, category, `year month day`, artwork lines, and `!!endrecord!!`. Albums exist only in memory. This prototype has fixed collection limits and basic input validation. Import-time maintenance corrected media parsing, missing-record handling, date-filter argument order and cancel/EOF handling. See [provenance](PROVENANCE.md) for historical import context.

## Validation

Run `python tests/verify.py` with g++ on PATH. It builds in a temporary folder and checks album creation, category/date filters, cancellation, deletion, EOF handling and an unterminated media record. These checks use the synthetic fixtures bundled here.

## Historical snapshots

Related files and saved edits from the same day are grouped into a single repository snapshot. Repeated editor saves within a day are consolidated; the latest preserved file state for that day is retained. Dates follow surviving file or editor records. These are retrospective imports, not claims that the original work was pushed to GitHub on those dates. Existing contributor Git histories remain intact. See [HISTORY.md](HISTORY.md) for the grouping policy.
