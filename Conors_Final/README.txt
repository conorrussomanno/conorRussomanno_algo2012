FINAL PROJECT README

The algorithmic animation in lightning ball uses the concept of recursion to create random bolts of electricity. It is inspired by on the processing sketch done by Esteban Hufstedler:
http://www.openprocessing.org/sketch/2924

As well as this amazing slow-motion lightning GIF: http://i.imgur.com/8qV7l.gif

The lightningBall application will run without a ThinkGear Device and the frequency of the lighting is determined by the variable maxTimeBetweenBolts.

The lighningBall_brain sketch uses a neurosky device to control the frequency of the lightning with the users attention level, recorded by the commercial EEG device. The code, as written, requires a Neurosky mindset. If you want to use a mindwave mobile, you have to edit the testApp.cpp file, switching "/dev/tty.MindSet-DevB" switching to "/dev/tty.MindWaveMobile-DevA".

Lastly, for some reason I could not get these applications to work unless their folders (lightningBall and lightnightBall_brain) were placed directly in the addons folder. If someone can figure out why this is the case please let me know: conor.russomanno@gmail.com.

Cheers,

-Conor