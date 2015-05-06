all:
	gcc populate.c -I/usr/include/mysql -lmysqlclient -o populate; \
	gcc reader.c -I/usr/include/mysql -lmysqlclient -o reader
