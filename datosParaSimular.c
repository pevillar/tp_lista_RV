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
                   "Ariel", "Gabriel", "Oscar", "Luis", "Jeremias","Liliana", "Evangelina",
                   "Patricia", "Ernesto", "Maria del Carmen", "Maria Elisa", "Tamara",
                   "Yanina", "Miguel", "Monica", "Hector", "Enrrique","Teresa",
                   "Hector Rodolfo", "Olga", "Elsa", "Domingo", "Manuel", "Carlos",
                   "Juana Bautista", "Florencia Rosa", "Veronica Liboria", "Antonia",
                   "Francisco Humberto","Marta Ilda", "Elvira Teofila", "Nicolas Raul",
                   "Pablo Edgar", "Jesus Carlos", "Ramon Rafael", "Raquel", "Miriam",
                   "Carlos", "Isabel", "Ana", "Francisco","Pedro", "Oscar", "Elder",
                   "Anabella", "Nanci", "Soledad", "Dante", "Alejandro", "Adriana",
                   "Nicolas", "Rodriguez", "Sandra","Domingo Antonio", "Ruben", "Gabriela",
                   "Nilda Elsa", "Mari Rosa", "Cesar Juan", "Blas", "Nicolas Carlos",
                   "Jose Gabriel", "David Ricardo", "Lilia Ines", "Miguel Angel","Laura",
                   "Gladis", "Geronimo", "Carlos", "Raquel Aurora", "Anie", "Nora",
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
                   "Milton", "Enrrique", "Maria", "Federico", "Matias", "Miguel",
                   "Monica", "Hector", "Enrrique","Teresa",
                   "Hector Rodolfo", "Olga", "Elsa", "Domingo", "Manuel", "Carlos",
                   "Juana Bautista", "Florencia Rosa", "Veronica Liboria", "Antonia",
                   "Francisco Humberto","Marta Ilda", "Elvira Teofila", "Nicolas Raul",
                   "Pablo Edgar", "Jesus Carlos", "Ramon Rafael", "Raquel", "Miriam",
                   "Carlos", "Isabel", "Ana", "Francisco","Pedro", "Oscar", "Elder",
                   "Anabella", "Nanci", "Soledad", "Dante", "Alejandro", "Adriana",
                   "Nicolas", "Rodriguez", "Sandra","Domingo Antonio", "Ruben", "Gabriela",
                   "Nilda Elsa", "Mari Rosa", "Cesar Juan", "Blas", "Nicolas Carlos",
                   "Jose Gabriel", "David Ricardo", "Lilia Ines",
                   "Yamila", "Gabriela", "Lourdes", "Maria", "Lorena", "Luciana", "Agustina",
                   "Ariel", "Gabriel", "Oscar", "Luis", "Nancy","Liliana", "Evangelina",
                   "Patricia", "Ernesto", "Maria del Carmen", "Maria Elisa", "Tamara",
                   "Yanina", "Miguel", "Monica", "Hector", "Enrrique","Teresa",
                   "Hector Rodolfo", "Olga", "Elsa", "Domingo", "Manuel", "Carlos",
                   "Juana Bautista", "Florencia Rosa", "Veronica Liboria", "Antonia",
                   "Francisco Humberto","Marta Ilda", "Elvira Teofila", "Nicolas Raul",
                   "Pablo Edgar", "Jesus Carlos", "Ramon Rafael", "Raquel", "Miriam",
                   "Carlos", "Isabel", "Ana", "Francisco","Pedro", "Oscar",
                   "Elder", "Monica", "Noelia", "Mabel",
                   "Judith", "Gonzalo", "Ignacio", "Carl", "Esteban", "Julio",
                   "Benito", "Gabriela", "Nancy", "Nelida", "Maria Jose", "Maria Isabel",
                   "Cielita", "Pahola", "Emilia", "Patricia", "Jaquelina", "Elva",
                   "Maria Belen","Maria Isabel", "Ana Maria", "Betiana", "Nancy",
                   "Ramona", "Romina", "Leysa", "Aimara", "Marta", "Anabella",
                   "Lourdes", "Carina","Mercedes", "Sandra", "Victor", "Gabriel",
                   "Adrian", "Francisco", "Edgar", "Carlos",
                   "Juana Bautista", "Florencia Rosa", "Veronica Liboria", "Antonia",
                   "Francisco Humberto","Marta Ilda", "Elvira Teofila", "Nicolas Raul",
                   "Pablo Edgar", "Jesus Carlos", "Ramon Rafael", "Raquel", "Miriam",
                   "Carlos", "Isabel", "Ana", "Francisco","Pedro", "Oscar", "Elder",
                   "Anabella", "Nanci", "Soledad", "Dante", "Alejandro", "Adriana",
                   "Nicolas", "Rodriguez", "Sandra","Domingo Antonio", "Ruben", "Gabriela",
                   "Nilda Elsa", "Mari Rosa", "Cesar Juan", "Blas", "Nicolas Carlos",
                   "Jose Gabriel", "David Ricardo", "Lilia Ines", "Miguel Angel","Laura",
                   "Gladis", "Geronimo", "Carlos", "Raquel Aurora", "Anie", "Nora",
                   "Hugo", "Martha Adriana", "Silvia", "Ivana",
                   "Paula", "Cristina del Valle", "Analia", "Paola", "Ivana", "Rosana",
                   "Silvana", "Maria del Carmen", "Monica", "Noelia", "Mabel",
                   "Judith", "Gonzalo", "Ignacio", "Carl", "Esteban", "Julio",
                   "Benito", "Gabriela", "Nancy", "Nelida", "Maria Jose", "Maria Isabel",
                   "Cielita", "Pahola", "Emilia", "Patricia", "Jaquelina", "Elva",
                   "Maria Belen","Maria Isabel", "Ana Maria", "Betiana", "Nancy",
                   "Ramona", "Romina", "Leysa", "Aimara", "Marta", "Anabella",
                   "Lourdes", "Carina","Mercedes", "Sandra", "Victor", "Gabriel",
                   "Adrian", "Francisco", "Edgar", "Jesus Carlos", "Ramon Rafael", "Raquel","Miriam",
                   "Carlos", "Isabel", "Ana", "Francisco","Pedro", "Oscar", "Elder",
                   "Anabella", "Nanci", "Soledad", "Dante", "Alejandro", "Adriana",
                   "Nicolas", "Rodriguez", "Sandra","Domingo Antonio", "Ruben", "Gabriela",
                   "Nilda Elsa", "Mari Rosa", "Cesar Juan", "Blas", "Nicolas Carlos",
                   "Jose Gabriel", "David Ricardo", "Lilia Ines", "Miguel Angel","Laura",
                   "Gladis", "Geronimo", "Carlos", "Raquel Aurora", "Anie", "Nora",
                   "Hugo", "Martha Adriana", "Maria Luisa", "Lilian Rossana", "Maria Gimena",
                   "Daniela", "Marina", "Andrea", "Graciela", "Dina", "Betiana",
                   "Sergio", "Carlos",
                   "Juana Bautista", "Florencia Rosa", "Veronica Liboria", "Antonia",
                   "Francisco Humberto","Marta Ilda", "Elvira Teofila", "Nicolas Raul",
                   "Pablo Edgar", "Jesus Carlos", "Ramon Rafael", "Raquel", "Miriam",
                   "Carlos", "Isabel", "Ana", "Francisco","Pedro", "Oscar", "Elder",
                   "Anabella", "Nanci", "Soledad", "Dante", "Alejandro", "Adriana",
                   "Nicolas", "Rodriguez", "Sandra","Domingo Antonio", "Ruben", "Gabriela",
                   "Nilda Elsa", "Mari Rosa", "Cesar Juan", "Blas", "Nicolas Carlos",
                   "Jose Gabriel", "David Ricardo"};

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
                     "Vucovich", "Oliva", "Tapia","Robles", "Monier", "Arganiaraz",
                     "Sartori", "Heredia", "Ramos", "Barrionuevo", "Canova", "Perez",
                     "Heredia", "Aspitia", "Bazan","Bazan", "Gonzalez", "Artaza",
                     "Astrada", "Amuchastegui", "Ceballos", "Aspitia", "Maldonado",
                     "Menchaca", "Villagra", "Gomez", "Aliendro","Gonzalez",
                     "Gonzalez", "Valdes", "Moyano", "Vargas", "Nuniez", "Zabala",
                     "Assis", "Gatti", "Romero", "Heredia", "Saddi","Sanchez",
                     "Diaz", "Ruiz", "Aspitia", "Monier", "Monier", "Sacco",
                     "Ontivero", "Villagra", "Calandri","Castro", "Morello", "Sosa",
                     "Gomez","Morenbo", "Gonzalez", "Aratano", "Figueroa", "Cisterna",
                     "Cisterna", "Gallego","Lombardi", "Bordon", "Farias", "Torres",
                     "Britos", "Gonzalez", "Moyano", "Olima", "Collino", "Cravero",
                     "Andrades", "Herrera","Torres", "Longhini", "Oliva", "Barea",
                     "Albornoz", "Peralta", "Aspitia", "Arias", "Gonzalez", "Juarez",
                     "Nieto", "Aguero","Ferreyra", "Cresta", "Diaz", "Godoy",
                     "Ahumada", "Villagra", "Ferreyra", "Capdevilla", "Romero",
                     "Vucovich", "Oliva", "Tapia","Robles", "Monier", "Yaniceli",
                     "Moyano", "Olima", "Collino", "Cravero",
                     "Andrades", "Herrera","Torres", "Longhini", "Oliva", "Barea",
                     "Albornoz", "Peralta", "Aspitia", "Arias", "Gonzalez", "Juarez",
                     "Nieto", "Aguero","Ferreyra", "Cresta", "Diaz", "Godoy",
                     "Ahumada", "Villagra", "Ferreyra", "Capdevilla", "Romero",
                     "Vucovich", "Oliva", "Tapia","Robles", "Monier", "Arganiaraz",
                     "Sartori", "Heredia", "Ramos", "Barrionuevo", "Canova", "Perez",
                     "Heredia", "Aspitia", "Bazan","Bazan", "Gonzalez", "Artaza",
                     "Astrada", "Amuchastegui", "Ceballos", "Aspitia", "Maldonado",
                     "Menchaca", "Herrera", "Arroyo", "Luna", "Maldonado", "Krank",
                     "Tovares", "Ramirez",
                     "Rodriguez", "Leal", "Bazan", "Aguirre", "Zarate","Barrionuevo",
                     "Olmos", "Arevalo", "Perracino", "Villanueva", "Moreno", "Gonzalez",
                     "Barrera", "Hubaide", "Daparte", "Ramirez", "Marcomini","Capdevilla",
                     "Amuchastegui", "Figueroa", "Romero", "Nieto", "Cejas", "Yaryura",
                     "Rocha", "Godoy", "Heredia", "Nieto", "Castro","Aguilera", "Vega",
                     "Rojas", "Godoy", "Perracino", "Ferreyra", "Capdevilla", "Romero",
                     "Vucovich", "Oliva", "Tapia","Robles", "Monier", "Arganiaraz",
                     "Sartori", "Heredia", "Ramos", "Barrionuevo", "Canova", "Perez",
                     "Heredia", "Aspitia", "Bazan","Bazan", "Gonzalez", "Artaza",
                     "Astrada", "Amuchastegui", "Ceballos", "Aspitia", "Maldonado",
                     "Menchaca", "Villagra", "Gomez", "Aliendro","Gonzalez",
                     "Gonzalez", "Valdes", "Moyano", "Vargas", "Nuniez", "Zabala",
                     "Assis", "Gatti", "Romero", "Heredia", "Saddi","Sanchez",
                     "Diaz", "Ruiz", "Aspitia", "Monier", "Monier", "Sacco",
                     "Ontivero", "Villagra", "Ferreyra", "Capdevilla", "Romero",
                     "Vucovich", "Oliva", "Tapia","Robles", "Monier", "Arganiaraz",
                     "Sartori", "Heredia", "Ramos", "Barrionuevo", "Canova", "Perez",
                     "Heredia", "Aspitia", "Bazan","Bazan", "Gonzalez", "Artaza",
                     "Astrada", "Amuchastegui", "Ceballos", "Aspitia", "Maldonado",
                     "Menchaca", "Villagra", "Gomez", "Aliendro","Gonzalez",
                     "Gonzalez", "Valdes", "Moyano", "Vargas", "Nuniez", "Zabala",
                     "Assis", "Gatti", "Romero", "Heredia", "Saddi","Sanchez",
                     "Diaz", "Ruiz", "Aspitia", "Monier", "Monier", "Sacco",
                     "Ontivero", "Villagra", "Sosa",
                     "Maldonado", "Quinteros", "Ramirez", "Maldonado", "Cordoba", "Gonzalez",
                     "Blanquer", "Tamara", "Diaz","Simoni", "Munioz", "Lopez", "Simoni",
                     "Aratano", "Camino", "Attanasio", "Acevedo", "Rolhaiser", "Taborda",
                     "Zarate", "Calandri","Castro", "Morello", "Sosa", "Gomez",
                     "Morenbo", "Gonzalez", "Aratano", "Figueroa", "Cisterna", "Yaniceli",
                     "Cisterna", "Gallego","Lombardi", "Bordon", "Farias", "Torres",
                     "Britos", "Gonzalez", "Moyano", "Olima", "Collino", "Cravero",
                     "Andrades", "Herrera","Torres", "Longhini", "Oliva", "Barea",
                     "Albornoz", "Herrera", "Arroyo", "Luna", "Maldonado", "Krank", "Tovares", "Ramirez",
                     "Rodriguez", "Leal", "Bazan", "Aguirre", "Zarate","Barrionuevo",
                     "Olmos", "Arevalo", "Perracino", "Villanueva", "Moreno", "Gonzalez",
                     "Barrera", "Hubaide", "Daparte", "Ramirez", "Marcomini","Capdevilla",
                     "Amuchastegui", "Figueroa", "Romero", "Nieto", "Cejas", "Yaryura",
                     "Rocha", "Godoy", "Heredia", "Nieto", "Castro","Aguilera", "Vega",
                     "Rojas", "Godoy"};