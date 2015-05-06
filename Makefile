#Code of Tyrone Verburgt, Ion Comendant & Assylzhan Mussin.
all:
	gcc populate.c -I/usr/include/mysql -lmysqlclient -o populate; \
	gcc reader.c -I/usr/include/mysql -lmysqlclient -o reader
