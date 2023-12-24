# Projet de Dogfighter en Francais（French）

Ce projet <Dogfighter> a été réalisé par Runnian Lu  et Zhenshan Li. La page de Git_Univ:https://forge.univ-lyon1.fr/p2209010/lifapa_tp

DogFighter est un jeu-vidéo developpé en c++ en utilisant la SDL/SDL2. Ce projet de developpement à été réalisé dans le cadre de l'UE LIFAP4
Voir la page du cours :  https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4

Ce dossier contient un makefile permettant d'executer le code du jeu-vidéo.
le Dossier src contient les sous-dossiers /core /sdl2 et /txt qui contiennent les modules spécifiques du jeu. (fichiers .h .cpp .txt) 

Il peut se compiler sous Linux/ MacOS et Windows (avec WSL notamment) , avec la commande make depuis le dossier source(F9 sur Code::blocks).

## Installation et Compiler sur toutes OS

 ### Sous Linux

 Si vous êtes sous Linux, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Ouvrez un terminal et exécutez simplement la commande : `sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick`
 - Puis, depuis le dossier racine du jeu, exécutez, depuis votre terminal, la commande : `make`
 - Une fois la compilation terminée, exécutez la commande `./bin/Debug/Plane` pour lancer du jeu

- Remarque : Sous linux, l'instruction `CXX=g++` dans le Makefile
 Si la commande d'installation de la SDL/SDL2 ne fonctionne pas, référez-vous à la commande spécifique pour installer SDL/SDL2 selon votre distribution Linux.
 
 -Compilez le projet (F9) en mode DEBUG et exécutez le jeu depuis Code::Blocks cliquer Plane.cbp

 ### Sous macOS

 Pour compiler sous macOS, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Installez Homebrew si ce n'est pas déjà fait : `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
 - Installez les bibliothèques SDL2 : `brew install sdl2 sdl2_image sdl2_ttf sdl2_mixer`
 - Puis, depuis le dossier racine du jeu, exécutez la commande : `make`
 - Une fois la compilation terminée, exécutez la commande `./bin/Debug/Plane` pour lancer du jeu

- Remarque : Sous macOS, l'instruction `CXX=clang++` dans le Makefile

 ### Sous Windows avec Visual Studio

 Pour compiler sous Windows avec Visual Studio, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Téléchargez les bibliothèques SDL2 (https://www.libsdl.org/download-2.0.php) et décompressez-les
 - Créez un nouveau projet Visual Studio C++ et ajoutez les fichiers sources du jeu
 - Configurez les propriétés du projet pour inclure les répertoires d'en-tête et les bibliothèques de SDL2
 - Compilez le projet et exécutez le jeu depuis Visual Studio

 ### Sous Windows avec Code::Blocks

 Pour compiler sous Windows avec Code::Blocks, assurez-vous d'avoir SDL/SDL2 installé sur votre machine.
 - Téléchargez les bibliothèques SDL2 (https://www.libsdl.org/download-2.0.php) et décompressez-les
 - Créez un nouveau projet Code::Blocks C++ et ajoutez les fichiers sources du jeu
 - Configurez les propriétés du projet pour inclure les répertoires d'en-tête et les bibliothèques de SDL2
 - Compilez le projet (F9) en mode DEBUG et exécutez le jeu depuis Code::Blocks

### Préambule : si vous voulez un Linux sous Windows, vous pouvez installer WSL !

Voir la page de MicroSoft : https://learn.microsoft.com/en-us/windows/wsl/install

C'est léger, pratique, rapide et suffisant pour de nombreuses applications.
Windows/WSL est exactement comme une machine Linux avec des drivers minimalistes,
donc la gestion de certains périphériques commes la carte son ou l'accélération 3D peut ne pas marcher mais pour ce cours ca peut être suffisant.
Il faut parcontre que vous ayez installé XMing pour pouvoir ouvrir des fenêtres comme expliqué sur la page du cours.
Valgrind marche aussi !


 ### Pour installer SDL2
 Afin d'installer SDL2 sous Linux ou avec WSL/Windows, veuillez suivre les instructions ci-dessous avec soin :

 ```sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick```

 Veuillez noter que cette commande peut varier en fonction de votre distribution Linux. Consultez la documentation de votre distribution pour connaître la commande appropriée.

 ### Compilation en ligne de commande après l'installation de SDL2 et WSL (si nécessaire)
 Une fois SDL2 et WSL (le cas échéant) correctement installés, veillez à effectuer la compilation en ligne de commande avec prudence :

 - Depuis le répertoire racine du module image, exécutez attentivement la commande `make`.
 - Si la compilation ne s'effectue pas comme prévu, vérifiez minutieusement que les chemins d'inclusion spécifiés dans le fichier Makefile à la racine du projet correspondent à votre installation de SDL2 (par défaut `/usr/include`).
 - Adaptez les chemins d'inclusion si nécessaire, en fonction de votre configuration et de l'emplacement de l'installation SDL2.

## Contrôles&Tutoriels

- Si vous choisissez le mode souris:
- 	Utilisez la souris pour contrôler le mouvement de l'avion
- Si vous choisissez le mode clavier:
- 	Flèches directionnelles : Déplacez l'avion du joueur
- Flèches directionnelles : Déplacez l'avion du joueur
- Touche P : Mettre le jeu en pause
- Touche Q : Quitter le jeu
- Touche Esc : Retour au menu principal ou achat les armers
- Touche F : Tir de balles


## Fonctionnalités

- Différentes trajectoires de balles pour les améliorations d'armes.
- Notes statistiques Système basé sur le nombre d'ennemis détruits.
- Pause et reprise du jeu.
- Choisissez le mode de jeu, à la souris ou au clavier.
- Technologie de défilement en arrière-plan
- Le jeu dispose d'une bande sonore et d'un système de son.
- Différents types d'ennemis avec des comportements et des vitesses variables.
- Collectez des power-ups pour améliorer les armes du joueur.

## À propos du code(organisation)

Le projet est principalement écrit en C++ et utilise la bibliothèque SDL2 pour la gestion des graphismes, des événements et du son. Le code est organisé en plusieurs classes pour gérer différentes parties du jeu, telles que le joueur, les ennemis, les balles et les power-ups.
Toutes les sections SDL est séparée du reste du code, ce qui rend le jeu plus concis.

## Problèmes connus et améliorations possibles

- Des objets de ravitaillement pourraient être lâchés de manière aléatoire pour améliorer l'expérience de jeu du joueur.(Succès)
- Achats en boutique pour améliorer la vitesse de lancement des balles et les dégâts d'attaque en dépensant des points de joueur (une fois que la fonction de sang est ouverte).(Succès)
- Générer du sang ennemi et du sang de joueur pour augmenter la difficulté du jeu.(pas encore).
- Générer des ennemis avancés pour enrichir le jeu(pas encore).(pas encore)
- Affichage du nombre de dégâts lors de l'attaque des ennemis。(pas encore)
- La génération des ennemis et des power-ups pourrait être améliorée pour offrir une expérience de jeu plus variée.(Succès)
- La gestion des collisions pourrait être améliorée pour une détection plus précise entre les objets du jeu.(Succès)
- Les performances pourraient être optimisées pour fonctionner plus efficacement sur différents types de matériel.(Succès)

## Licence

Ce projet est sous licence Runnian LU(Manager) et Zhenshan LI.

## 中文运行简要说明：

这个 <Dogfighter> 项目由 Runnian Lu（主负责人） 和 Zhenshan Li 创建。法国Git_Univ 页面:https://forge.univ-lyon1.fr/p2209010/lifapa_tp

DogFighter 是一款使用 SDL/SDL2 的 c++ 开发的视频游戏。该开发项目是大学第二年结课设计的一部分。
参见课程页面：https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4

该文件夹包含一个用于执行视频游戏代码的 makefile 文件。
src 文件夹包含 /core /sdl2 和 /txt 子文件夹，其中包含游戏的特定模块（.h .cpp .txt 文件）。

在 Linux/MacOS 和 Windows 下（尤其是 WSL），可使用源代码文件夹中的 make 命令（Code::blocks 可用 F9）进行编译。

### 经测试该项目可在所有操作系统上安装和编译：

### 在 Linux 上

 如果您运行的是 Linux，请确保您的计算机上安装了 SDL/SDL2。
 - 打开终端并运行以下命令：`sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick`。
 - 然后，在游戏根目录下的终端运行以下命令：`make`。
 - 编译完成后，运行"./bin/Debug/Plane "命令启动游戏。
 
- 注意：在 Linux 环境下，Makefile 中的指令 `CXX=g++` 是不正确的。
- 如果 SDL/SDL2 安装命令不起作用，请参阅安装 SDL/SDL2 的特定命令，具体取决于您的 Linux 发行版。
- 在 DEBUG 模式下编译项目（F9），然后从 Code::Blocks 点击 Plane.cbp 运行游戏。

### 在 macOS 上

 要在 macOS 下编译，请确保您的电脑已安装 SDL/SDL2。
 - 如果尚未安装，请安装 Homebrew：`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
 - 安装 SDL2 库：`brew install sdl2 sdl2_image sdl2_ttf sdl2_mixer`。
 - 然后，在游戏根目录下运行命令：`make`。
 - 编译完成后，运行"./bin/Debug/Plane "命令启动游戏。

- 注意：在 macOS 上，Makefile 文件中的指令 `CXX=clang++` 应为"./bin/Debug/Plane"。

### 在 Windows 下使用 Visual Studio

 要在 Windows 下使用 Visual Studio 进行编译，请确保您的计算机上安装了 SDL/SDL2。
 - 下载 SDL2 库 (https://www.libsdl.org/download-2.0.php) 并解压缩。
 - 创建一个新的 Visual Studio C++ 项目并添加游戏源文件
 - 配置项目属性以包含 SDL2 头文件目录和库
 - 编译项目并从 Visual Studio 运行游戏

### 在 Windows 下使用 Code::Blocks

 要在 Windows 上使用 Code::Blocks 进行编译，请确保您的计算机上安装了 SDL/SDL2。
 - 下载 SDL2 库 (https://www.libsdl.org/download-2.0.php) 并解压缩。
 - 创建一个新的 Code::Blocks C++ 项目并添加游戏源文件
 - 配置项目属性以包含 SDL2 头文件目录和库
 - 在 DEBUG 模式下编译项目（F9），然后从 Code::Blocks 运行游戏

#### 前言：如果想在 Windows 上运行 Linux，亦可以安装 WSL！

请参阅 MicroSoft 网页：https://learn.microsoft.com/en-us/windows/wsl/install

### 安装 SDL2
 要在 Linux 或 WSL/Windows 下安装 SDL2，请仔细按照以下说明操作：

 ``sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick````

 请注意，此命令可能因 Linux 发行版而异。请查阅您的发行版文档以获取相应的命令。

### 安装 SDL2 和 WSL 后的命令行编译（如有必要）
 正确安装 SDL2 和 WSL（如适用）后，请注意从命令行进行编译：

 - 在映像模块的根目录下，小心运行 `make` 命令。
 - 如果编译未按预期进行，请仔细检查项目根目录下 Makefile 中指定的包含路径是否与 SDL2 的安装一致（默认为 `/usr/include`）。
 - 如有必要，请根据您的配置和 SDL2 的安装位置调整 include 路径。

## 控制与教程

- 如果选择鼠标模式：
- 使用鼠标控制飞机的移动
- 如果选择键盘模式
- 方向箭头： 移动玩家的飞机
- 方向箭头：移动玩家的飞机
- P 按钮：暂停游戏
- Q 键：退出游戏
- Esc 键：返回主菜单或购买武器
- F 键：发射子弹


### 特点

- 不同的子弹弹道用于武器升级。
- 基于消灭敌人数量的统计说明系统。
- 暂停和继续游戏
- 选择游戏模式，鼠标或键盘
- 背景滚动技术
- 游戏具有配乐和声音系统。
- 不同类型的敌人，其行为和速度各不相同。
- 收集升级玩家武器的道具。

### 关于代码（组织）

该项目主要用 C++ 编写，使用 SDL2 库管理图形、事件和声音。代码分为多个类，用于管理游戏的不同部分，如玩家、敌人、子弹和能量加成。
所有 SDL 部分都与其他代码分开，使游戏更加简洁。

### 最后关于已知问题和可能的改进

- 可随机掉落补给物品，以增强玩家的体验（成功）
- 通过消耗玩家点数在商店购买提高子弹发射速度和攻击伤害的物品（血液功能开启后）（成功）
- 生成敌人和玩家的血量，增加游戏难度（尚未）。
- 生成高级敌人，丰富游戏内容（尚未推出）。
- 显示攻击敌人时的伤害量。
- 可以改进敌人和强力道具的生成，以提供更丰富的游戏体验（成功）
- 可以改进碰撞处理，以便更准确地检测游戏中的物体。
- 可以优化性能，以便在不同类型的硬件上更高效地运行（成功）