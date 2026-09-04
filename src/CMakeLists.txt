add_executable(low-level_setup
 main.cpp
        Opdrachten/test.cpp
        Opdrachten/test.hpp
)

target_link_libraries(low-level_setup
 PUBLIC
  ImGui-SFML::ImGui-SFML
)
