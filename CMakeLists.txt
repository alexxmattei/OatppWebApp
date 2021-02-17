cmake_minimum_required(VERSION 3.1)

set(project_name my-project) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib
	ShoppingAPI/APIController/Products/ProductsController.h
	Models/Accessory.cpp
	Models/BoardGame.cpp
	Models/Book.cpp
	Models/Client.cpp
	Models/HomeDeco.cpp
	Models/Magazine.cpp
	Models/Movie.cpp
	Models/Music.cpp
	Models/Product.cpp
	Models/Tea.cpp
	Models/Wine.cpp
	Helpers/Reader.h
	HeaderModels/Accessory.h
	HeaderModels/BoardGame.h
	HeaderModels/Book.h
	HeaderModels/Client.h
	HeaderModels/HomeDeco.h
	HeaderModels/Magazine.h
	HeaderModels/Movie.h
	HeaderModels/Music.h
	HeaderModels/Product.h
	HeaderModels/Tea.h
	HeaderModels/Wine.h
	HeaderFiles/ApiClient.h
	HeaderFiles/ApiModels.h
	HeaderFiles/SyncSimpleExample.h
	DTOs/DefaultDto.hpp
	DTOs/ProductDto.hpp
	DTOs/ClientDto.hpp
	HeaderModelsList/BookList.h
	HeaderModelsList/AccessoryList.h
	HeaderModelsList/BoardGameList.h
	HeaderModelsList/HomeDecoList.h
	HeaderModelsList/ClientList.h
	HeaderModelsList/MagazineList.h
	HeaderModelsList/MovieList.h
	HeaderModelsList/MusicList.h
	HeaderModelsList/TeaList.h
	HeaderModelsList/WineList.h
	HeaderModelsList/ProductList.h
	HeaderControllers/AccessoriesController.h
	HeaderControllers/BoardGamesController.h
	HeaderControllers/BooksController.h
	HeaderControllers/HomeDecoController.h
	HeaderControllers/MagazinesController.h
	HeaderControllers/MoviesController.h
	HeaderControllers/MusicController.h
	HeaderControllers/TeasController.h
	HeaderControllers/WinesController.h
	HeaderControllers/ClientController.h
	HeaderModels/ShoppingPlatformAppComponent.h
	Helpers/Reader.cpp
	ModelsList/BookList.cpp
	ModelsList/BoardGameList.cpp
	ModelsList/AccessoryList.cpp
	ModelsList/HomeDecoList.cpp
	ModelsList/ClientList.cpp
	ModelsList/MagazineList.cpp
	ModelsList/MovieList.cpp
	ModelsList/TeaList.cpp
	ModelsList/MusicList.cpp
	ModelsList/WineList.cpp
	ModelsList/ProductList.cpp
	Helpers/Reader.cpp
	textFiles/Books.txt
	textFiles/Accessories.txt
	textFiles/BoardGames.txt
	textFiles/Clients.txt
	textFiles/HomeDeco.txt
	textFiles/Magazines.txt
	textFiles/Movies.txt
	textFiles/Music.txt
	textFiles/Tea.txt
	textFiles/Wines.txt
	textFiles/Products.txt

)

## link libs

find_package(oatpp 1.2.0 REQUIRED)


target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test

)

target_include_directories(${project_name}-lib PUBLIC src)

## add executables

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Books.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Accessories.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/BoardGames.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Clients.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/HomeDeco.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Magazines.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Movies.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Music.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Tea.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Wines.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textFiles/Products.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${project_name}-exe
        sourcefiles/StartApp.cpp
	test/startapp/MyApiTestClient.hpp
	
	)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
	test/tests.cpp
        test/startapp/TestComponent.hpp
	test/startapp/MyApiTestClient.hpp
	test/MyControllerTest.cpp
        test/MyControllerTest.hpp
   
)

target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)
set_target_properties(${project_name}-lib ${project_name}-exe PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)


enable_testing()
add_test(project-tests ${project_name}-test)
