# Skeletyl Handwire Build Log

## Motivation
There is going to be some online-recipe style introduction here, so go ahead and [skip to the main content](link) if that's what you're here for. 

I had started out by building a 5x6 dactyl manuform with a 5 thumb cluster. I initially built the keyboard after seeing lots of coworkers with RSI and deciding that I really did not want to follow in their sorry footsteps. The dactyl was fun, but I found that it had far too many keys. I didn't like stretching my pinkies to hit keys, and I far preferred a numpad layer over using the number row. I settled on the Skeletyl because it kept all the dactyl-like features I enjoyed (curved keywells, aggressive pinkie stagger, integrated tenting, thumb clusters) while ditching all the things I didn't like about my keyboard (too many keys, too loud). I also wanted to fix some of my own mistakes from the first time around: using linear instead of clicky switches (I don't wanna hear it, they're fun), using bitbanging instead of i2c, and using Elite-Cs instead of Pro Micros.

## Planning
The Skeletyl is an open-source case design from BastardKB, so huge shoutout to him for the quality of the keyboard design and for making it free for all the rest of us. You can find the files for the Skeletyl [here](https://github.com/Bastardkb/Skeletyl). **Note that the maintainer of the repo is constantly updating the Skeletyl's design, and some or all of my discussion re: the case and printing it are not guaranteed to be accurate.**

### Bill of Materials
#### Case
- Marble White PLA+ (Duramic3D, Amazon)
- 12x M3 Brass Self-Tapping Heat-Set Threaded Inserts (Amazon)
- 10x Rubber Feet (Amazon)
- 8x M3x8mm Countersunk Hex Screws (Amazon)
- 4x M3x12mm Countersunk Hex Screws (Amazon)
- Ender 3 V2 (obviously optional if you have access to a printing shop or a cool friend with a printer)

#### Electronics
- 2x Elite C (Canadian Vendor)
- 2x TRRS Jack (Amazon)
- 22 AWG Wire (White, Single-Core) (Amazon)
- 30 AWG Wire (Black, Braided Silicone)
- 2x 4.7k Resistor (for i2c)
- 36x Through-Hole Diode (Amazon)

#### Keyboard Parts
- IDOBAMAO [?] White Keycaps (Drop)
- Gateron Oil Kings (Shockport)
- Custom TRRS/USB-C Cables (peetabyte)

#### Tools
- Soldering station
	- Soldering Iron
	- Lead-free Solder
	- Fume Removal Fan
	- Desoldering Pump (Optional)
- Tweezers
- Pliers
- X-Acto Knife
- Sandpaper (High Grit)
- Digital Calipers

I already had some parts left over from my original Dactyl build that I wanted to use in the Skeletyl to save some money. Most of these were agnostic across handwired boards, but my heat-set inserts were too small for the original build. I'm not especially good with CAD work, but I can throw something together in TinkerCAD if I really need to. Unfortunately, as a web app, it can only handle so many triangles, and when I imported the Skeletyl files there was a clear loss of resolution. My solution ended up being to use the low-res import as a template to position some hollowed-out cylinders inside of the existing mounting holes. I then exported only the cylinders as a single object, and opened both that and the original Skeletyl `.stl` in Cura. I set the overlap settings to merge objects, and voilà: a high-resolution Skeletyl with M3-compatible insert slots. I also needed to increase the size of the cutouts for the feet in the baseplate, but I did not need as high a resolution print for the plates and was able to modify them directly in TinkerCAD.

Because I was going to be handwiring the board rather than going with the flexible PCB route, I needed a way to mount my Elite-C and TRRS sockets in place. Lucky for me, there is a Pro Micro adapter on the BastardKB Github page, and modifying it to accept an Elite-C, TRRS socket, and my size of screw was trivial. You can find the finished `.stl` files for everything I printed in the resources section of this guide.

### Printing
Printing the Skeletyl was very straightforward. I mostly followed the directions on the BastardKB [docs page](https://docs.bastardkb.com/hc/en-us/articles/360020031180-Print-settings-for-Dactyls). Some of the print settings described weren't applicable to me as I use Cura and not Slic3r, but I found that my rough translation of the listed settings worked well enough. You can find the exact settings profile I used in the resources section of this guide.

My printer is running a modified version of Marlin called JeyersUI (shoutout Jeyers, if you have an Ender I highly recommend using this distro). I have UBL enabled using Creality's BLTouch, and I print on smooth tempered glass with a thin coat of Elmer's Purple Glue. (Aside/flex/recommendation: since I did those three things, I have never had an issue with bed adhesion. Perfect first layers, every time.)

The prints took a total of about 3 days to finish (working _almost_ nonstop). Make sure you don't get impatient and pull them off before they're completely cool (the build plate should register room temperature) or you can wind up with warping and ruin hours of printing effort. Don't ask me how I know.

#### Post-Processing
Again, I more or less followed the BastardKB guide here. Get some good pliers and twist the supports. I would recommend starting with the thumb - I've found that it always comes out the most easily, and lets you work your way across the rest of the build. You can twist/yank as hard as you want without fear of damaging the case, just **make sure you're only grabbing the support before you pull**. 

Once you've got the supports out, this is a good time to sand the case if you're planning on it. I personally didn't; I found that printing with the marble filament does a great job of hiding layer lines, especially on a well-tuned printer. I'd recommend not trimming the elephant's foot off of the baseplates and ignoring the bottom of the case halves for now (if you printed with a brim, there are going to be some flash lines there.) This is so that you can sand the plate and keyboard while they're connected to make sure you get a perfectly flush fit.

### Assembly
#### Inserts/Bottom Plates
I started by installing the brass inserts first. Once again, BastardKB's [recommended method of installation](https://docs.bastardkb.com/hc/en-us/articles/4415744775570-Prepare-the-case) worked perfectly, although my version also has threaded inserts for the daughterboard mounts, rather than pegs or self-tapping screws. I used the flat side of a large bolt to press the inserts into place. If you do the same, **be very careful not to press too hard**. The heat from the inserts softens the PLA enough to make it easily deformed by too much pressure. If it gets warped a little, it's not the end of the world. Just try bending it back into place _gently_ while the plastic is still malleable.

Once the inserts are in place and cool to the touch, go ahead and test-fit the bottom plates by screwing them in. Once you're satisfied with the fitment, this is the time to sand down the lip between the case and the baseplate. It's better to do it now so that you don't get any dust in your switches.

You can go ahead and add the feet to the bottom plate now, if you haven't already. I scored the plate with an X-Acto before installing them to get better adhesion.

#### Wiring
This is the majority of the work, so prepare yourself for a lot of soldering and tedious wire positioning. I'd recommend putting on some music and having fun with it. Tips for success before you start:

1. **Don't get impatient!** This is just something that takes a while. Mistakes are _easy to make_ and _hard to fix_. Double or triple check your work at the start and end of every step.

1. **Make a plan!** It can be the way I did it, or something that works better for you, but plan as far ahead with the wiring as you can. This means everything from the order in which you wire your rows/columns/keys, the guage of wire you want to use, how you'll be routing the wires to get them to the Elite-C, etc. Again: this is not hard to do, but because there are a lot of steps it is _easy to fuck up_. 

1. **Don't get cocky!** A soldering iron and the Skeletyl case do not mix. It will melt instantly and horribly. Always be aware of the positioning of your iron, especially around the bottom of the case. Even a quick graze will at worst ruin the case and at best make more work for you. If you're having trouble reaching a key from the position you're working in, step back and reassess. And don't even think about sticking the soldering iron through the big hole in the side of the case.

Back to the show!

There are a lot of different ways to handwire a keyboard, many of which are conveniently covered in [this section](https://docs.qmk.fm/#/feature_split_keyboard) of the QMK documentation. That said, I assume you're reading this to see how I wired mine, but it's there if you want to read it. I do my wiring in three steps: Rows, columns, and daughterboard. I find that this allows me to more easily inspect my work and fix any mistakes I made at each juncture, as generally speaking these three steps are disjoint but build on top of one another. Also, doing things in batches assembly-line style makes it go a lot faster. 

1. **Rows**
	- I follow the standard-ish split handwire method of making my rows using diode legs and my columns using insulated wire. This reduces the amount of work I need to do, as you'll see when we get to the columns. 
	- Diode direction is not actually all that important; if your diodes are the 'wrong way' it just means that you need to flip the polling direction in the software at the end. What is _very_ important is that all the diodes are facing the same way. I wired mine with the black stripe facing away from the switch. Keep it consistent across both halves!
	- I start by counting out the number of diodes I need, then tearing off a strip and bending all of them on one side at a 90º angle. This helps me keep track of which end is which after I remove the diode from the tape.