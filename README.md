# Fillit

__Fillit__ est un projet vous permettant de decouvrir et/ou de vous familiariser avec
une problematique récurrente en programmation : la recherche d’une solution optimale
parmi un très grand nombre de possibilités, dans un délai raisonable. Dans le cas de ce
projet, il s’agira d’agencer des *Tetriminos* entre eux et de déterminer le plus petit carré
possible pouvant les acueillir.
Un *Tetriminos* est une figure géométrique formée de 4 blocs que vous connaissez
grâce au célèbre jeu Tetris.

![Tetriminos](https://static.abcteach.com/content_preview/t/tetrominos_puzzle_turtle_p-1.png "Tetriminos")

Le programme prends en entrée un (et un seul) fichier décrivant la liste des *Tetriminos* à agencer.

La description d’un Tetrimino doit respecter les règles suivantes :
- Exactement 4 lignes de 4 caractères suivis d’un retour à la ligne.
- Un Tetriminos est une pièce de Tetris classique composée de 4 blocs.
- Chaque caractère doit être, soit un ’#’ lorsque la case correspond à l’un des 4
blocs d’un Tetriminos, soit un ’.’ lorsque la case est vide.
- Chaque bloc d’un Tetriminos doit être en contact avec au moins un autre bloc
sur l’un ou l’autre de ses 4 côtés.
```
Quelques exemples de descriptions de Tetriminos valides :
....    ....    ####    ....    .##.    ....    .#..    ....    ....
..##    ....    ....    ....    ..##    .##.    ###.    ##..    .##.
..#.    ..##    ....    ##..    ....    ##..    ....    #...    ..#.
..#.    ..##    ....    ##..    ....    ....    ....    #...    ..#.
```
```
Quelques exemples de descriptions de Tetriminos invalides :
####    ...#    ##...   #.    ....    ..##    ####    ,,,,    .HH.
...#    ..#.    ##...   ##    ....    ....    ####    ####    HH..
....    .#..    ....    #.    ....    ....    ####    ,,,,    ....
....    #...    ....          ....    ##..    ####    ,,,,    ....
```
