# Horoscope Reader

## By: Natalie Abrams (nba28)


I have created a Horoscope reader. Simply input your birthday, and it will print out a horoscope matching your appropriate horoscope sign. 

The goal for this project was to create something I could give to my mom as a gift. She loves horoscopes and I was excited to try lots of different parts that we had yet to use during the semester, and combine them with techniques we learned throughout. 

The system will fully run on an Arudino, with various connected components. 


### Initial Vision

![](./initial-vision.JPG)


### Paper Prototype

[Initial Project Proposal](./project-proposal.pdf)


The paper prototype demonstrates the look and the feel of the machine.

![](paper-prototype.JPG)


### Verplank Diagram

![](image here)


### Expected Parts

- Arduino
- Keypad (https://www.adafruit.com/product/419)
- OLED display (https://www.adafruit.com/product/1673)
- Thermal Printer (https://www.adafruit.com/product/2753)
- Acrylic (for the exterior box)
- Extra paper for the printer (https://www.adafruit.com/product/2754)


### Interaction Plan

Users will approach the machine and enter their birthday on the keypad followed by the "#" sign. Then on the display, it will show which horoscope matches your birthday and the pritner will print out your horoscope for you to take with you!

### First steps

The first step I took was to get all of the parts working together within the same Arduino code, all connected to the breadboard we were given in class. 

![](./breadboard.JPG)

My next step was to transfer those components onto a proto board so that all of the parts would be much more compact, resulting in a better looking outcome and a smaller box. 

![](./perm-board.JPG)
![](./back-perm-board.JPG)


Now that all of the components were soldered together, I wanted to start designing the box to put them in. Here is the first cardboard prototype that I cut on the laser printer. 

![](./proto1-a.JPG)
![](./proto1-b.JPG)

While this worked, I needed to create more accurate dimensions for all the appropriate slots and holes, because the final box was being printed on acrylic. 

Here are the final plans from Adobe Illistrator:

[Illustrator file](./box-nabrams.ai)

[PDF version](./box-pdf.pdf)


### Putting it all together

![](./progress.JPG)

### Final Box Design

![](./final4.JPG)
![](./final1.JPG)
![](./final2.JPG)
![](./final3.JPG)


## The code

Initially, I was going to use both the Arduino and Rasberri Pi so that I could pull horoscopes from a Horoscope API I found, allowing for new and unique horoscopes everyday. I was unable to get the API to work with the Pi, so I scaled back my expectations and decided that the printer would print a generic reading for each symbol. 

I also discovered that the Arduino does not have enough memory to store all of the symbols for the horoscopes I wanted to print along with the reading, so I had to do some thinking. I decided that the Libra logo was the most important, because my mom is a Libra, so the rest of the readings print out without a unique symbol. 





### Failures

- Orginally I planned to use the rasberri pi but it proved too complex for the time we were given to complete the assignment. I decided to focus on more important things
-I was not able to print the logo for each horoscope sign due to the size capacity of the Ardunio being too small




## Final Video
