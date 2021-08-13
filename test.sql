CREATE TABLE UFR
(
	code VARCHAR(50) PRIMARY KEY,
	libelle VARCHAR(50) NOT NULL,
	site VARCHAR(50),
	directeur VARCHAR(50) NOT NULL
);

CREATE TABLE filiere
(
	codeUFR VARCHAR(50) NOT NULL,
	sigle VARCHAR(50) PRIMARY KEY,
	nom VARCHAR(50) NOT NULL,
	domaine VARCHAR(50) NOT NULL,
	responsable VARCHAR(100), 
	FOREIGN KEY (codeUFR) REFERENCES UFR(code)
);

CREATE TABLE membre
	matricule INTEGER CHECK(matricule BETWEEN 1 and 2019),
	nom VARCHAR(50) NOT NULL,
	prenom VARCHAR(30) NOT NULL,
	age INTEGER,
	adresse VARCHAR(100)
);

CREATE TABLE cotisation
	num INTEGER,
	ine VARCHAR(50) NOT NULL,
	prenom VARCHAR(50) NOT NULL,
	dateCotis DATE NOT NULL,
	matricule INTEGER CHECK(matricule BETWEEN 1 and 2019),
	FOREIGN KEY (matricule) REFERENCES UFR(matricule)
);


CREATE TABLE inscription
(
	annee DATE NOT NULL,
	ineEtudiant VARCHAR(50) NOT NULL,
	sigleFiliere VARCHAR(50) NOT NULL,
	FOREIGN KEY ineEtudiant REFERENCES etudiant(ine) ,
	FOREIGN KEY (sigleFiliere) REFERENCES filiere(sigle)
);