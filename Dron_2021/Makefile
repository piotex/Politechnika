CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: workingFile

	./workingFile

workingFile: obj/main.o obj/Wirniki.o obj/Graniastoslup.o obj/Dron.o obj/Scena.o obj/Dr3D_gnuplot_api.o obj/Plaszczyzna.o obj/Figura3D.o obj/Prostopadloscian.o obj/Wzgorze.o obj/Plaskowyz.o obj/Ostroslup.o obj/MacierzObrotu.o obj/Wektor.o obj/MacierzKw.o 
	g++ -Wall -pedantic -o workingFile obj/*.o  -lpthread 

obj/main.o: src/main.cpp obj/Wirniki.o obj/Graniastoslup.o inc/Dron.hh inc/Scena.hh inc/Dr3D_gnuplot_api.hh inc/Plaszczyzna.hh inc/Figura3D.hh inc/Prostopadloscian.hh inc/Wzgorze.hh inc/Plaskowyz.hh inc/Ostroslup.hh inc/MacierzObrotu.hh  inc/Wektor.hh inc/MacierzKw.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp			
	
obj/Ostroslup.o: src/Ostroslup.cpp inc/Ostroslup.hh 
	g++ ${CPPFLAGS} -o obj/Ostroslup.o src/Ostroslup.cpp

obj/Plaskowyz.o: src/Plaskowyz.cpp inc/Plaskowyz.hh 
	g++ ${CPPFLAGS} -o obj/Plaskowyz.o src/Plaskowyz.cpp
	
obj/Wzgorze.o: src/Wzgorze.cpp inc/Wzgorze.hh 
	g++ ${CPPFLAGS} -o obj/Wzgorze.o src/Wzgorze.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Figura3D.o: src/Figura3D.cpp inc/Figura3D.hh 
	g++ ${CPPFLAGS} -o obj/Figura3D.o src/Figura3D.cpp

obj/Plaszczyzna.o: src/Plaszczyzna.cpp inc/Plaszczyzna.hh 
	g++ ${CPPFLAGS} -o obj/Plaszczyzna.o src/Plaszczyzna.cpp

obj/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh 
	g++ ${CPPFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

obj/Wirniki.o: src/Wirniki.cpp inc/Wirniki.hh 
	g++ ${CPPFLAGS} -o obj/Wirniki.o src/Wirniki.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh 
	g++ ${CPPFLAGS} -o obj/Scena.o src/Scena.cpp

obj/MacierzObrotu.o: src/MacierzObrotu.cpp inc/MacierzObrotu.hh 
	g++ ${CPPFLAGS} -o obj/MacierzObrotu.o src/MacierzObrotu.cpp

obj/MacierzKw.o: src/MacierzKw.cpp inc/MacierzKw.hh src/MacierzKw_temp.cpp
	g++ ${CPPFLAGS} -o obj/MacierzKw.o src/MacierzKw_temp.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh src/Wektor_temp.cpp
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor_temp.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh 
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

obj/Dron.o: src/Dron.cpp inc/Dron.hh 
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

clean:
	rm -f obj/*.o workingFile