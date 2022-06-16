#include <stdio.h>
#include <string.h>

char *arregloMaterias[] = {"sistemas de representacion", "algoritmos y programacion i",
                           "analisis matematico i", "algebra i",
                           "introduccion a la problematica del mundo contemporaneo",
                           "algoritmos y programacion ii", "fisica i", "algebra ii",
                           "problemas de historia del siglo XX", "estructura de datos",
                           "disenio logico", "analisis matematico ii", "matematica discreta",
                           "cuestiones de sociologia, economia y politica",
                           "algoritmos y programacion iii", "arquitectura de computadoras i",
                           "fisica ii", "matematicas especiales", "cultura contemporanea",
                           "sistemas operativos", "fundamentos de computacion",
                           "fisica iii", "probabilidad y estadistica",
                           "laboratorio de microprocesadores", "teoria de circuitos electronicos",
                           "arquitectura de computadoras ii", "comunicacion de datos",
                           "disenio y arquitectura de sistemas de computacion", "electronica",
                           "base de datos", "redes de computadoras",
                           "construccion de sistemas de computacion", "ingenieria de calidad",
                           "procesamiento de seniales", "analisis numerico", "quimica",
                           "organizacion de proyectos", "ingenieria de software",
                           "ingenieria de requerimientos", "sistemas embebidos",
                           "sistemas de tiempo real", "trabajo final integrador",
                           "practica profesional supervisada", "economia y legislacion",
                           "seguridad, salud ocupacional y medio ambiente",
                           "metodologia de la investigacion"};

char *nombres[] = {"Yamila", "Gabriela", "Lourdes", "Maria", "Lorena", "Luciana", "Agustina",
                  "Ariel", "Gabriel", "Oscar", "Luis", "Nancy","Liliana", "Evangelina",
                  "Patricia", "Ernesto", "Maria del Carmen", " Maria Elisa", "Tamara",
                  "Yanina", "Miguel", "Monica", "Hector", "Enrrique","Teresa",
                  "Hector Rodolfo", "Olga", "Elsa", "Domingo", "Manuel", "Carlos",
                  "Juana Bautista", "Florencia Rosa", "Veronica Liboria", "Antonia",
                  "Francisco Humberto","Marta Ilda", " Elvira Teofila", "s Nicolas Raul ",
                  "Pablo Edgar", "Jesus Carlos", "Ramon Rafael", "Raquel", "Miriam",
                  "Carlos", "Isabel", "Ana", "Francisco","Pedro", "Oscar", "Elder",
                  "Anabella", "Nanci", "Soledad", "Dante", "Alejandro", "Adriana",
                  "Nicolas", "Rodriguez", "Sandra","Domingo Antonio", "Ruben", "Gabriela",
                  "Nilda Elsa", "Mari Rosa", "Cesar Juan", "Blas", " Nicolas Carlos",
                  "Jose Gabriel", "David Ricardo", " Lilia Ines", " Miguel Angel","Laura",
                  "Gladis", "Geronimo", "Carlos", " Raquel Aurora", "Anie", "Nora",
                  "Hugo", "Martha Adriana", "Maria Luisa", "Lilian Rossana", "Maria Gimena",
                  "Daniela", "Marina", "Andrea", "Graciela", "Dina", "Betiana",
                  "Sergio", "Ayelen", "Elio", "Daniela", "Yamila", "Alfonsina",
                  "Vicenta","Patricia", "Mercedes", "Molina Macarena", "Silvia", "Ivana",
                  "Paula", "Cristina del Valle", "Analia", "Paola", "Ivana", "Rosana",
                  "Silvana", "Maria del Carmen", "Monica", "Noelia", "Mabel",
                  "Judith", "Gonzalo", "Ignacio", "Carl", "Esteban", "Julio",
                  "Benito", "Gabriela", "Nancy", "Nelida", "Maria Jose", "Maria Isabel",
                  "Cielita", "Pahola", "Emilia", "Patricia", "Jaquelina", "Elva",
                  "Maria Belen","Maria Isabel", "Ana Maria", "Betiana", "Nancy",
                  "Ramona", "Romina", "Leysa", "Aimara", "Marta", "Anabella",
                  "Lourdes", "Carina","Mercedes", "Sandra", "Victor", "Gabriel",
                  "Adrian", "Francisco", "Edgar", "Oscar", "Yanina", "Roxana",
                  "Crescencia", "Paula","Virginia", "Silvina", "Sandra", "Cintia",
                  "Milton", "Enrrique", "Maria", "Federico", "Matias",};

char *apellidos[] = {"Herrera", "Arroyo", "Luna", "Maldonado", "Krank", "Tovares", "Ramirez",
                     "Rodriguez", "Leal", "Bazan", "Aguirre", "Zarate","Barrionuevo",
                     "Olmos", "Arevalo", "Perracino", "Villanueva", "Moreno", "Gonzalez",
                     "Barrera", "Hubaide", "Daparte", "Ramirez", "Marcomini","Capdevilla",
                     "Amuchastegui", "Figueroa", "Romero", "Nieto", "Cejas", "Yaryura",
                     "Rocha", "Godoy", "Heredia", "Nieto", "Castro","Aguilera", "Vega",
                     "Rojas", "Godoy", "Juarez", "Rivero", "Moreno", "Eluani", "Luna",
                     "Cagnelutti", "Bustos", "Luna","Diaz", "Monier", "Sosa",
                     "Maldonado", "Quinteros", "Ramirez", "Maldonado", "Cordoba", "Gonzalez",
                     "Blanquer", "Tamara", "Diaz","Simoni", "Munioz", "Lopez", "Simoni",
                     "Aratano", "Camino", "Attanasio", "Acevedo", "Rolhaiser", "Taborda",
                     "Zarate", "Calandri","Castro", "Morello", "Sosa", "Gomez",
                     "Morenbo", "Gonzalez", "Aratano", "Figueroa", "Cisterna", "Yaniceli",
                     "Cisterna", "Gallego","Lombardi", "Bordon", "Farias", "Torres",
                     "Britos", "Gonzalez", "Moyano", "Olima", "Collino", "Cravero",
                     "Andrades", "Herrera","Torres", "Longhini", "Oliva", "Barea",
                     "Albornoz", "Peralta", "Aspitia", "Arias", "Gonzalez", "Juarez",
                     "Nieto", "Aguero","Ferreyra", "Cresta", "Diaz", "Godoy",
                     "Ahumada", "Villagra", "Ferreyra", "Capdevilla", "Romero",
                     "Vucovich", "Oliva", "Tapia","Robles", "Monier", "Argañaraz",
                     "Sartori", "Heredia", "Ramos", "Barrionuevo", "Canova", "Perez",
                     "Heredia", "Aspitia", "Bazan","Bazan", "Gonzalez", "Artaza",
                     "Astrada", "Amuchastegui", "Ceballos", "Aspitia", "Maldonado",
                     "Menchaca", "Villagra", "Gomez", "Aliendro","Gonzalez",
                     "Gonzalez", "Valdes", "Moyano", "Vargas", "Nuniez", "Zabala",
                     "Assis", "Gatti", "Romero", "Heredia", "Saddi","Sanchez",
                     "Diaz", "Ruiz", "Aspitia", "Monier", "Monier", "Sacco",
                     "Ontivero", "Villagra"};

int anios[] = {2001, 2000, 2002, 2003, 2001, 2000, 2002, 2003, 2001, 2000,
               2001, 2000, 2002, 2003, 2001, 2000, 2002, 2003, 2001,
               1998, 1999, 1993, 1994, 1995, 1996, 1997, 1998, 1999,
               1993, 1994, 1995, 1996, 1997, 1998, 1999, 1993, 1994,
               1995, 1996, 1997, 1998, 1999, 1993, 1994, 1995, 1996,
               1997, 1998, 1999, 1993, 1994, 1995, 1996, 1997, 1998,
               1999, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 1999,
               1981, 1982, 1983, 1984, 1985, 1986, 1987, 1981, 2001,
               2000, 2002, 2003, 2001, 2000, 2002, 2003, 2001, 2000,
               1982, 1983, 1984, 1985, 1986, 2002, 2003, 2001, 2000,
               1987, 1981, 1982, 1983, 1984, 1985, 1986, 1987, 1981,
               1982, 1983, 1984, 1985, 1986, 1987, 1981, 1982,
               1983, 1984, 1985, 1986, 1987, 1981, 1982, 1983,
               1984, 1985, 1986, 1987, 1981, 1982, 1983, 1984,
               1985, 1986, 1987, 1979, 1978, 2003, 1988, 2001,
               2000, 2002, 1979, 1978, 2003, 1988, 2001, 2000,
               2002, 1979, 1978, 2003, 1988, 2001, 2000,
               2002, 1979, 1978, 2003, 1988, 2001, 2000, 2002,
               1979, 1978, 2003, 1988, 2001, 2000, 2002, 1979,
               1978, 2003};

int meses[] = {3, 7, 2, 5, 3, 7, 2, 5, 3, 7, 2, 5, 3,
               7, 2, 5, 3, 7, 2, 5, 3, 7, 2, 5, 3,
               7, 2, 5, 3, 7, 2, 5, 3, 7, 2, 5, 9,
               7, 12, 11, 9, 7, 12, 11, 9, 7, 12, 11,
               9, 7, 12, 11, 9, 7, 12, 11, 9, 7, 12,
               11, 9, 7, 12, 11, 9, 7, 12, 11, 9, 7,
               12,11, 6, 8, 10, 4, 6, 8, 10, 4, 6, 8,
               10, 4, 6, 8, 10, 4, 6, 8, 10, 4, 6, 8,
               10, 4, 6, 8, 10, 4, 6, 8, 10, 4, 6,
               8, 10, 4, 11, 9, 3, 1, 11, 9, 3, 1,
               11, 9, 3, 1, 11, 9, 3, 1, 11, 9, 3,
               1, 11, 9, 3, 1, 11, 9, 3, 1, 11, 9,
               3, 1, 11, 9, 3, 1, 11, 9, 3, 1, 11,
               9, 3, 1, 11, 9, 3, 1, 11, 9, 3, 1,
               11, 9, 3, 1, 11};

int dias[] = {11, 9, 3, 1, 11, 9, 3, 1, 11, 9, 3, 1, 11,
              9, 3, 1, 11, 9, 3, 1, 11, 9, 3, 1, 15,
              23, 7, 3, 11, 25, 15, 23, 7, 3, 11, 25, 15,
              23, 7, 3, 11, 25, 15, 23, 7, 3, 11, 25, 15,
              23, 7, 3, 11, 25, 15, 23, 7,3, 11, 25, 15,
              23, 7, 3, 11, 25, 15, 23, 7, 3, 11, 25, 15,
              23, 7, 3, 11, 25, 12, 21, 9, 1, 13, 22, 12,
              21, 9, 1, 13, 22, 12, 21, 9, 1, 13, 22, 12,
              21, 9, 1, 13, 22, 12, 21, 9, 1, 13, 22,
              12, 21, 9, 1, 13, 22, 12, 21, 9, 1, 13,
              22, 12, 21, 9, 1, 13, 22, 12, 21, 9, 1,
              13, 22, 10, 4, 8, 10, 4, 8, 10, 4, 8,
              10, 4, 8, 10, 4, 8, 10, 4, 8, 10, 4,
              8, 10, 4, 8, 10, 4, 8, 8, 10, 4, 8,
              10, 4,
              };

int dnis[] = {43000041, 43018467, 43006334, 43026500, 43019169, 43015724, 43011478,
              43029358, 43026962, 43024464, 43005705, 43028145,
              43023281, 43016827, 43009961, 43000491, 43002995, 43011942, 43004827,
              43005436, 43032391, 43014604, 43003902, 43000153,
              43000292, 43012382, 43017421, 43018716, 43019718, 47000041, 47018467,
              47006334, 47026500, 47019169, 47015724, 47011478, 47029358, 47026962,
              47024464, 47005705, 47028145,
              47023281, 47016827, 47009961, 47000491, 47002995, 47011942, 47004827,
              47005436, 47032391, 47014604, 47003902, 47000153,
              47000292, 47012382, 47017421, 47018716, 47019718, 47019895, 47005447,
              47021726, 47014771, 47011538, 47001869, 47019912,
              47025667, 47026299, 47017035, 47009894, 47028703, 47023811, 47031322,
              47030333, 47017673, 47004664, 47015141, 47007711,44000041, 44018467,
              44006334, 44026500, 44019169, 44015724, 44011478, 44029358, 44026962,
              44024464, 44005705, 44028145,
              44023281, 44016827, 44009961, 44000491, 44002995, 44011942, 44004827,
              44005436, 44032391, 44014604, 44003902, 44000153,
              44000292, 44012382, 44017421, 44018716, 44019718, 44019895,
              44021726, 44014771, 44011538, 44001869, 44019912, 44005447,
              44025667, 44026299, 44017035, 44009894, 44028703, 44023811,
              44031322, 44030333, 44017673, 44004664, 44015141, 44007711,
              44028253, 37000041, 37018467, 37006334, 37026500, 37019169,
              37015724, 37011478, 37029358, 37026962, 37024464, 37005705,
              37028145, 37023281, 37016827, 37009961, 37000491, 37002995,
              37011942, 37004827, 37005436, 37032391, 37014604, 37003902,
              37000292, 37012382, 37017421, 37018716, 37019718, 37019895,
              37005447, 37021726, 37014771, 37011538, 37001869, 37019912,
              37025667, 37026299, 37017035, 37000153};