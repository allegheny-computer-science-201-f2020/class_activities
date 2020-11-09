# CMPSC 201 Activity 11

## Tasks

There are a number of programs in the `src` directory to facilitate the class discussion. Each program contains a comment header that contains commands for compiling and running these programs.

For the class activity please complete the TOD tags in `lists.hs` by using [Learn You a Haskell](http://learnyouahaskell.com/starting-out#an-intro-to-lists).

## Using `progator` Docker image

If you haven't done so already during activity5, please pull the newest [progator](https://hub.docker.com/repository/docker/janyljumadinova/progator) image by running the following command:

`docker pull janyljumadinova/progator`

You can check that you have the `progator` image by running the following command and verifying that you see `progator` in the list of your Docker images:

`docker image list`

Then, run the docker container and mount your "activity6" directory as a volume by replacing `your-path/local/working/directory` in the following command with the path to your "activity6" directory:

_Mac OS_:

`docker run -d -p 80:80 -v /your-path/local/working/directory/:/root/environment janyljumadinova/progator`

_Linux OS_:

May need to use `sudo` as:

`sudo docker run -d -p 80:80 -v /your-path/local/working/directory/:/root/environment janyljumadinova/progator`

_Windows OS_ (note the quotes in path):

`docker run -d -p 80:80 -v "C:\Users\your-path/":/root/environment janyljumadinova/progator`

You can check that you have correctly started the Docker container:

`docker container list`

## Stopping the `progator` container and pruning

When you are finished working with `progator` do not forget to stop `progator` container by getting the container ID from the command you ran in your terminal:

`docker container list`

and then stopping the container by running the following command (replacing `container-ID` with the actual `progator` container ID in your terminal:

`docker container stop container-ID`

You should also remove all unused containers and images (both dangling and unreferenced) by running the following command:

`docker system prune -a`
