dep_sdl2 = dependency('sdl2', required: true)

window_sources = files(
  'window/Screen.cc'
)

vectors_sources = files()

executable('raytracer', 
  sources: ['main.cpp'] + window_sources + vectors_sources,
  include_directories: include_directories('window', 'vectors'),
  dependencies: [dep_sdl2]
)
