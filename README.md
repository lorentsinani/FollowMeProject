# Follow Me Project

Follow me is a simulation of a set of musical clips. Clips start playing when they are triggered. Clips can also have Follow Actions , which allow creating groups of clips that can trigger each other. 

A clip can have one or two Follow Actions that define what happens after a clip has been playing for a set amount of time. Every Follow Action has an associated Chance value that controls the likelihood of each of the two Follow Actions occurring.

This project was given as a Task from University of Pristina.


## Usage

Once the application is running you need to provide valid inputs. The inputs are of two types.

First, you need to provide all the clips to be played. It creates a named clip with a set of properties. (The name of the clip has to be a word without spaces for example 'Do').

clip <name> <ticks to play> <follow chance1> <follow chance 2> <action1> <action2>

Second, you need the ticks command, which runs the program a certain number of ticks.
If the optional list of floating point numbers is provided the output is made deterministic, otherwise the output is random (taking into account the chances of every action)

ticks <ticks to play> <...optional list of floating point numbers>

## Design

You will find in this project comments in everything we did and used. 
But overall this project was designed and approached using a double linked list to store the different clips.

## Authors

-Lorent Sinani
-Lorik Mustafa