#Vélos de vieux

Ces explications ne valent que pour un utilisateur ayant un système d'exploitation UNIX. Ce logiciel n'a PAS été testé sur d'autres systèmes d'exploitation.

##Installation

Afin que l'application puisse s'installer et fonctionner correctement, veuillez vérifier que les paquets suivants soient installés :

 * `libmysqlclient-dev`
 * `mysql-client`
 * `mysql-server`

Lors de l'installation de `mysql-server`, au moment du choix du mot de passe de l'utilisateur 'root', entrez "rootsql" comme mot de passe.

Si vous avez déjà installé ce paquet et entré un différent mot de passe pour l'utilisateur 'root', merci de bien vouloir changer celui-ci grâce à cette commande (après vous être connecté à votre base de données) : 
``` UPDATE user SET password=PASSWORD("rootsql") WHERE user='root' ;```

_Pour remettre votre mot de passe habituel, remplacez seulement "rootsql" par celui-ci dans la commande ci-dessus._

##Compilation de l'application

**TO DO**
**Cliquez (clic droit) sur le dossier décompressé -> Ouvrir dans un terminal -> commande `make``-> lancement d'un script de création d'icône sur le Bureau ou lancement du programme depuis le terminal**

##Problèmes rencontrés

En cas de problème non expliqué précédemment, veuillez détailler celui-ci à l'adresse mail suivante : tao.grolleau@gmail.com