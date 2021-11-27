libckbref = static_library(
    'ckbref', [
        'fixuni.c',
        'dispsm.c',
        'prinst.c',
        'timecn.c',
        'repmcw.c',
         ],
   include_directories : includes)

ckbrief = executable(
    'ckbrief', [ 'ckbrief.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libckbref, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
