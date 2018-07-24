drop table Velo;

create table Velo (
	numero INT PRIMARY KEY,
   	nom VARCHAR(30),
	prenom VARCHAR(20),
	sexe INT,
	observations VARCHAR(50),
	profession VARCHAR(30),
	patron VARCHAR(20),
	utilisation VARCHAR(50),
	homme_femme INT,
    marque VARCHAR(15),
	etat VARCHAR(15),
	requisition VARCHAR(30),
	image VARCHAR(200)
);

insert into Velo values (1, "Grolleau", "Tao", 0, "", "étudiant", "fac", "travail", 0, "SM", "bon", "", "");
insert into Velo values (2, "Grolleau", "Sami", 0, "", "étudiant", "fac", "loisir", 1, "SM", "excellent", "", "");
insert into Velo values (3, "Grolleau", "Marc", 0, "", "libraire", "Librairie Et Caetera", "loisir", 0, "Cazenac", "mauvais", "", "");

