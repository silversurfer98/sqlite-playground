project('sqlite_db', 'c', 'cpp', default_options: ['c_std=c11', 'cpp_std=c++17'])

subdir('sqlite')

indir = include_directories('sqlite')
indir_db = include_directories('../databases')

src = ['charOperations.h','charOperations.cpp','main.cpp']
executable('out', src, link_with: sqlite, include_directories: [indir, indir_db])