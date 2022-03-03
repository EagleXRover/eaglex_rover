#!/bin/bash

sudo docker run -p 8080:8080 -d -t -v ~/mapproxy:/mapproxy danielsnider/mapproxy

# exit gracefully by returning a status 
exit 0