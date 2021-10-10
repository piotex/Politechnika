CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: workingFile

	./workingFile

workingFile: obj/main.o obj/LiczbaZespolona.o obj/PrzeszkodaPrent.o obj/FactoryPrzeszkody.o obj/PrzeszkodaProstopadloscian.o obj/Sruba.o obj/Graniastoslup.o obj/Plaszczyzna_Wody.o obj/Dron.o obj/Dr3D_gnuplot_api.o obj/Plaszczyzna.o obj/Figura3D.o obj/Prostopadloscian.o obj/MacierzObrotu.o obj/Wektor.o obj/MacierzKw.o 
	g++ -Wall -pedantic -o workingFile obj/*.o  -lpthread 

obj/main.o: src/main.cpp obj/LiczbaZespolona.o obj/PrzeszkodaPrent.o obj/FactoryPrzeszkody.o obj/PrzeszkodaProstopadloscian.o obj/Sruba.o obj/Graniastoslup.o obj/Plaszczyzna_Wody.o inc/Dron.hh inc/Dr3D_gnuplot_api.hh inc/Plaszczyzna.hh inc/Figura3D.hh inc/Prostopadloscian.hh inc/MacierzObrotu.hh  inc/Wektor.hh inc/MacierzKw.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp			

obj/LiczbaZespolona.o: src/LiczbaZespolona.cpp inc/LiczbaZespolona.hh 
	g++ ${CPPFLAGS} -o obj/LiczbaZespolona.o src/LiczbaZespolona.cpp

obj/PrzeszkodaPrent.o: src/PrzeszkodaPrent.cpp inc/PrzeszkodaPrent.hh 
	g++ ${CPPFLAGS} -o obj/PrzeszkodaPrent.o src/PrzeszkodaPrent.cpp

obj/FactoryPrzeszkody.o: src/FactoryPrzeszkody.cpp inc/FactoryPrzeszkody.hh 
	g++ ${CPPFLAGS} -o obj/FactoryPrzeszkody.o src/FactoryPrzeszkody.cpp

obj/PrzeszkodaProstopadloscian.o: src/PrzeszkodaProstopadloscian.cpp inc/PrzeszkodaProstopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/PrzeszkodaProstopadloscian.o src/PrzeszkodaProstopadloscian.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Figura3D.o: src/Figura3D.cpp inc/Figura3D.hh 
	g++ ${CPPFLAGS} -o obj/Figura3D.o src/Figura3D.cpp

obj/Plaszczyzna.o: src/Plaszczyzna.cpp inc/Plaszczyzna.hh 
	g++ ${CPPFLAGS} -o obj/Plaszczyzna.o src/Plaszczyzna.cpp

obj/Plaszczyzna_Wody.o: src/Plaszczyzna_Wody.cpp inc/Plaszczyzna_Wody.hh 
	g++ ${CPPFLAGS} -o obj/Plaszczyzna_Wody.o src/Plaszczyzna_Wody.cpp

obj/Graniastoslup.o: src/Graniastoslup.cpp inc/Graniastoslup.hh 
	g++ ${CPPFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

obj/Sruba.o: src/Sruba.cpp inc/Sruba.hh 
	g++ ${CPPFLAGS} -o obj/Sruba.o src/Sruba.cpp

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