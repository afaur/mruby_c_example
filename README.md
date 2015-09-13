## Notes

This is an example of loading mruby code at runtime that can use c functions as
exposed modules.

C Source for the experimental mruby sqlite gem (https://github.com/mattn/mruby-sqlite3)
has been manually added in to this repo to show an example of how mruby gems work.

## Running

~~~
./compile.sh && ./mruby_c_example
~~~

## Included files

Project includes `qo` inside the bin directory (https://github.com/andlabs/qo) which makes compiling easier.
