libdskbrief = static_library(
    'dskbrief', [
        'attcmp.c',
        'sum02.c',
        'dskb04.c',
        'dskd04.c',
        'sum04.c',
        'grpseg.c',
        'dspgap.c',
        'dski04.c',
        'prcinf.c',
        'dspdsc.c',
        'cortab.c',
         ],
   include_directories : includes)

dskbrief = executable(
    'dskbrief', [ 'dskbrief.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libdskbrief, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
