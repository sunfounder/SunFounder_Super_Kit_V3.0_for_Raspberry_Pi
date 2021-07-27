Lesson 8 4N35
===============

Introduction
----------------

The 4N35 is an optocoupler for general purpose application. It consists
of gallium arsenide infrared LED and a silicon NPN phototransistor. When
the input signal is applied to the LED in the input terminal, the LED
lights up. After receiving the light signal, the light receiver then
converts it into electrical signal and outputs the signal directly or
after amplifying it into a standard digital level. Thus, the transition
and transmission of electricity-light-electricity is completed. Since
light is the media of the transmission, meaning the input terminal and
the output one are isolated electrically, this process is also be known
as electrical isolation.

Components
----------------

\- 1 \* Raspberry Pi

\- 1 \* 4N35

\- 1 \* LED

\- 1 \* 220 Ohm Resistor

\- 1\* 1k Ohm Resistor

\- Some jump wires

\- 1 \* T-Extension Board

\- 1 \* 40-Pin GPIO Cable

Principle
----------------

**4N35**

.. image:: media/image147.png
    :align: center

The 4N35 is an optocoupler for general purpose application. It consists
of gallium arsenide infrared LED and a silicon NPN phototransistor.

What an optocoupler does is to break the connection between signal
source and signal receiver, so as to stop electrical interference. In
other words, it is used to prevent interference from external electrical
signals. 4N35 can be used in AV conversion audio circuits. Broadly it is
widely used in electrical insulation for a general optocoupler.

.. image:: media/image148.png
    :align: center

See the internal structure of 4N35 above. Pin 1 and 2 are connected to
an infrared LED. When the LED is electrified, it'll emit infrared rays.
To protect the LED from burning, usually a resistor (about 1K) is
connected to pin 1. Then the NPN phototransistor is power on when
receiving the rays. This can be done to control the load connected to
the phototransistor. Even when the load short circuit occurs, it won't
affect the control board, thus realizing good electrical isolation.

The Schematic Diagram:
-------------------------

.. image:: media/image149.png
    :align: center

**Principle:** In this experiment, use an LED as the load connected to
the NPN phototransistor. Connect pin 2 of 4N35 to pin B17, pin 1
connects a 1K current-limiting resistor and then a 3.3V. Connect pin 4
to GND, and pin 5 to the cathode of the LED. Then hook the anode of the
LED to 3.3V after connecting with a 220 Ohm resistor. When in program, a
LOW level is given to pin B17, the infrared LED will emit infrared rays.
Then the phototransistor receives infrared rays and gets electrified,
and the LED cathode is LOW, thus turning on the LED. Also you can
control the LED by circuits only – connect pin 2 to ground and it will
brighten.

**Step 1:** Build the circuit.

.. image:: media/image150.png
    :align: center

For C Language Users:
^^^^^^^^^^^^^^^^^^^^^^^

**Step 2**: Open the code file.

.. code-block::

    cd/home/pi/SunFounder_Super_Kit_V3.0_for_Raspberry_Pi/C

**Step 3:** Compile the Code.

.. code-block::

    make 08_4N35

**Step 4:** Run the executable file above.

.. code-block::

    sudo ./08_4N35

**Code Explanation**

.. code-block:: C

    digitalWrite(_4N35Pin, LOW); /* set the I/O port as low level (0V), thus
    the optocoupler is energized, and the pin connected to LED conducts to
    the 0V. Then the LED lights up.*/

    delay(500); 
    // optocoupler is a kind of electronic device and there is no limitation on its on-off frequency.

    digitalWrite(_4N35Pin, HIGH); /* set I/O port as high level (3.3V), thus
    the optocoupler is not energized ,and the pin connected to LED cannot
    conduct to the 0V. Then the LED goes out.*/

For Python Users:
^^^^^^^^^^^^^^^^^^

**Step 2:** Open the code file.

.. code-block:: 

    cd/home/pi/SunFounder_Super_Kit_V3.0_for_Raspberry_Pi/Python

**Step 3:** Run.

.. code-block:: 

    sudo python3 08_4N35.py

**Code Explanation**

.. code-block:: python

    GPIO.output(Pin_4N35, GPIO.LOW) # set the pins of optocoupler as low
    #level, thus the optocoupler is energized, and the pin connected to LED
    #conducts to the 0V.Then the LED lights up.

    time.sleep(0.5) #wait for 0.5 second. The on-off frequency of the
    #optocoupler can be changed by modifying this parameter.

    GPIO.output(Pin_4N35, GPIO.HIGH) # set the pins of optocoupler as high
    #level, thus the optocoupler is disconnected, and the pin connected to
    #LED break the connection to the 0V. Then the LED goes out.

    time.sleep(0.5)

You will see the LED blinks.

.. image:: media/image151.png
    :align: center