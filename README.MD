# Projet C - Arthur V

Le programme en langage C offre deux modes : génération de condensats et recherche de chaînes parmi des condensats. Il prend en charge des entrées depuis un fichier ou le flux standard d'entrée. Les condensats sont générés à l'aide de l'algorithme SHA-256. Le programme peut être exécuté via Docker. 


## Table des matières

- [Installation](#installation)
- [Utilisation](#utilisation)


## Installation

shell

    sudo apt-get install libssl-dev 

    git clone https://github.com/minedark94/Projet-C.git

    cd Projet-C

    make

Docker

    sudo docker build -t projetc:latest .

## Utilisation

shell

Exemple d'utilisation mode G: 

    cat rockyou.txt |./projet-bin -G -o rockyou.corresp

Exemple d'utilisation mode L: 

    echo "75e5441a4cf226d2149d45f5609dcce0cf4dee3fad1dd14db54390cf0f772cba" | ./projet-bin -L -i rockyou.corresp


Docker

    sudo docker run --rm -ti -v $(pwd):/app  mon_programme:latest /bin/bash

ou (dependant du système)

    sudo docker run --rm -ti -v ./:/app  mon_programme:latest /bin/bash


Par la suite utiliser le programme comme un shell classic


