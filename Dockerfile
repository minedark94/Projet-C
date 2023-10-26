# Utilisez l'image officielle GCC en tant qu'image de base
FROM gcc:latest

# Copiez les fichiers sources et le Makefile dans le conteneur
COPY src /app/src
COPY Makefile /app/Makefile

# Définissez le répertoire de travail
WORKDIR /app

# Compilez le programme C en utilisant le Makefile
RUN make

# Commande d'exécution par défaut (ajustez-la en fonction de votre programme)
CMD ["./projet-bin"]
