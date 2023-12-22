cmake               = import('cmake')
options             = cmake.subproject_options()
options.add_cmake_defines({'RC_ENABLE_GTEST': 'ON'})

rapidcheck_project  = cmake.subproject('rapidcheck', options: options)
rapidcheck          = rapidcheck_project.dependency('rapidcheck')
rapidcheck_gtest    = rapidcheck_project.dependency('rapidcheck_gtest')

gtest         = dependency('gtest')
dependencies  = [gtest, rapidcheck, rapidcheck_gtest, control_dep]

gain          = executable(        'test-gain',         'test-gain.cpp', dependencies:dependencies)
proportional  = executable('test-proportional', 'test-proportional.cpp', dependencies:dependencies)
integral      = executable(    'test-integral',     'test-integral.cpp', dependencies:dependencies)
differential  = executable('test-differential', 'test-differential.cpp', dependencies:dependencies)

test(        'test-gain',         gain)
test('test-proportional', proportional)
test(    'test-integral',     integral)
test('test-differential', differential)
