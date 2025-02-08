# Pokemon's cries quizz !

> This project is being developed by Romain ROSANO.

## Source

The idea of this project is inspired by the [Pokemoncries's website](https://pokemoncries.com/).  
This project is using the [PokeAPI](https://pokeapi.co/) to get the Pokemon's cries.


## Presentation

This project is a simple quizz game where you have to guess the Pokemon's name by listening to its cry.  
The pokemon's cry will be played 3 times with 10 seconds between each play, thanks to the phone's speaker.  
After the 3rd play, the pokemon's name and its picture will be displayed on the ESP8266's screen.  
The game will choose 5 random pokemons to be guessed among the 1024 pokemons available in the PokeAPI.


## How to use it

To use this project, you will need :
- An ESP8266 board (with a screen and a WiFi module)
- A phone with a speaker and an access point (value to be set in the `env.h` file)


## How the application works

The application is divided into 4 main parts:
- First, the ESP8266 will connect to the WiFi access point and will get the 5 random pokemons to be guessed.
- Then, the ESP8266 will play the pokemon's cry 3 times with 10 seconds between each play.
- After the 3rd play, the ESP8266 will display the pokemon's name and its picture on the screen.
- The both previous steps will be repeated for each pokemon to be guessed.


## Demonstration

Here is a demonstration of the project on Youtube: [TODO]()