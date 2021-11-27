libchronos = static_library(
    'chronos', [
        'crcnst.c',
        'cronos.c',
        'dsplay.c',
        'ls.c',
        'lstmid.c',
        'speakr.c' ],
    include_directories : includes)

chronos = executable(
    'chronos', [ 'chronos.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libchronos, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
