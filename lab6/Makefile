BUILD_DIR = build

app: client server
.PHONY: app

server: server.cpp algo.cpp create_build_dir
		g++ server.cpp algo.cpp -o $(BUILD_DIR)/server 
.PHONY: app

client: client.cpp create_build_dir
		g++ client.cpp -o $(BUILD_DIR)/client
.PHONY: client

create_build_dir: 
		mkdir -p $(BUILD_DIR)
.PHONY: create_build_dir

clean_project:
		rm -rf $(BUILD_DIR)
.PHONY: clean_project


