libfrmdif = static_library(
    'frmdif', [
        'sc01s2d.c',
        'getqav.c',
        'ldklst.c',
        'ckcovr.c',
        'dr2str.c',
        'chwcml.c',
        'et2str.c',
        'dpstrp.c',
        'rtdiff.c',
         ],
   include_directories : includes)

frmdiff = executable(
    'frmdiff', [ 'frmdiff.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libfrmdif, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
