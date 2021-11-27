libmsopck = static_library(
    'msopck', [
        'zzmckdmp.c',
        'mkfclk.c',
        'linrot_m.c',
         ],
   include_directories : includes)

msopck = executable(
    'msopck', [ 'msopck.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libmsopck, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
