Lesson 10 Slide Switch
========================

Introduction
----------------

In this lesson, we will learn how to use a Slide Switch. Usually, the
slide switch is soldered on PCB as a power switch, but here we need to
insert it into the breadboard, thus it may not be tightened. And we use
it on the breadboard is to show its function.

Components
----------------

\- 1 \* Raspberry Pi

\- 1 \* T-Extension Board

\- 1 \* 40-Pin GPIO Cable

\- 1 \* Breadboard

\- 1 \* Slide Switch

\- 2 \* LED

\- 3 \* Resistors (220Ω,10kΩ)

\- 1 \* USB cable

\- Jumper wires

\- 1 \* 104 Capacitor Ceramic

Principle
----------------

**Slide Switch**

.. image:: media/image156.png
   :align: center

A slide switch, just as its name implies, is to slide the switch bar to
connect or break the circuit, and further switch circuits. The
common-used types are SPDT, SPTT, DPDT, DPTT etc. The Slide Switch is
commonly used in low-voltage circuit. It features flexibility and
stability, and widely applies in electric instruments and electric toys.

How it works: Use the middle pin as the fixed one. When you pull the
slide to the left, the left two pins are connected; to the right, the
right two pins connected. Thus, it connects and disconnects circuits as
a switch. See the figure below:

.. image:: media/image157.png
   :align: center

The circuit symbol of the slide switch is as shown below. 2 in the
figure means the middle pin.

.. image:: media/image158.png
   :align: center

**Principle:** Connect the middle pin of the Slide Switch to B17, and
two LEDs to pin B18 and B27 respectively. Then when you pull the slide,
you can see the two LEDs light up alternately.

.. image:: media/image159.png
   :align: center
Experimental Procedures
----------------------------

**Step 1:** Build the circuit.

.. image:: media/image161.png
   :align: center

For C Language Users:
^^^^^^^^^^^^^^^^^^^^^^^^^^

**Step 2**: Go to the folder of the code.

.. code-block::

   cd/home/pi/SunFounder_Super_Kit_V3.0_for_Raspberry_Pi/C

**Step 3:** Compile.

.. code-block::

   make 10_slideSwitch

**Step 4:** Run the executable file above.

.. code-block::

   sudo ./10_slideSwitch

**Code Explanation**

.. code-block:: C

   /* When the slide is pulled to the left, the middle pin and left one are
   connected; the Raspberry Pi reads a high level at the middle pin, so the
   LED1 is on and LED2 off */

   if(digitalRead(slidePin) == 1)
   {

      digitalWrite(led1, LOW);

      digitalWrite(led2, HIGH);

      printf("LED1 on\n");

   }

   /* When the slide is pulled to the right, the middle pin and right one
   are connected; the Raspberry Pi reads a low, so the LED2 is on and LED1
   off */

   if(digitalRead(slidePin) == 0)
   {

      digitalWrite(led2, LOW);

      digitalWrite(led1, HIGH);

      printf(".....LED2 on\n");

   }

For Python Users:
^^^^^^^^^^^^^^^^^^^^^^^^

**Step 2:** Get into the folder of the code.

.. code-block::

   cd/home/pi/SunFounder_Super_Kit_V3.0_for_Raspberry_Pi/Python

**Step 3:** Run.

.. code-block::

   sudo python3 10_slideSwitch.py

**Code Explanation**

.. code-block:: python

   '''When the slide is pulled to the left, the middle pin and left one are
   connected; the Raspberry Pi reads a high level at the middle pin, so the
   LED1 is on and LED2 off. '''

   if GPIO.input(slidePin) == 1:

      print (" LED1 ON ")

      GPIO.output(led1Pin, GPIO.LOW)

      GPIO.output(led2Pin, GPIO.HIGH)

   '''When the slide is pulled to the right, the middle pin and right one are
   connected; the Raspberry Pi reads a low, so the LED2 is on and LED1 off.'''

   if GPIO.input(slidePin) == 0:

      print (" LED2 ON ")

      GPIO.output(led2Pin, GPIO.LOW)

      GPIO.output(led1Pin, GPIO.HIGH)

Now pull the slide, and you can see the two LEDs light up alternately.

.. image:: media/image162.png
   :align: center