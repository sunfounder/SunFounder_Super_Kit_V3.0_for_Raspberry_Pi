Lesson 7 Relay
=================

Introduction
--------------

As we know relay is a device which is used to provide connection between
two or more points or device in response to the input signal applied. In
another words relay provide isolation between the controller and the
device as we know devices may work on AC as well as on DC. However, they
receive signals from microcontroller which works on DC hence we require
a relay to bridge the gap. Relay is extremely useful when you need to
control a large amount of current or voltage with small electrical
signal.

Components
--------------

\- 1 \* Raspberry Pi

\- 1 \* Breadboard

\- 1 \* Relay

\- 1 \* LED

\- 1 \* Resistor (220Ω)

\- 1 \* Resistor (1KΩ)

\- 1 \* NPN Transistor

\- 1 \* Diode (Rectifier)

\- Several jumper wires

\- 1 \* T-Extension Board

\- 1 \* 40-Pin GPIO Cable

Principle
--------------

**Relay**

There are 5 parts in every relay:

1. **Electromagnet** – It consists of an iron core wounded by coil of
wires. When electricity is passed through, it becomes magnetic.
Therefore, it is calLED electromagnet.

2. **Armature** – The movable magnetic strip is known as armature. When
current flows through them, the coil is it energized thus producing a
magnetic field which is used to make or break the normally open (N/O) or
normally close (N/C) points. And the armature can be moved with direct
current (DC) as well as alternating current (AC).

3. **Spring** – When no currents flow through the coil on the
electromagnet, the spring pulls the armature away so the circuit cannot
be completed.

4. Set of electrical **contacts** – There are two contact points:

-  Normally open - connected when the relay is activated, and disconnected when it is inactive.

-  Normally close – not connected when the relay is activated, and connected when it is inactive.

5. Molded frame – Relays are covered with plastic for protection.

Working of Relay
-------------------

The working principle of relay is simple. When power is supplied to the
relay, currents start flowing through the control coil; as a result, the
electromagnet starts energizing. Then the armature is attracted to the
coil, pulling down the moving contact together thus connecting with the
normally open contacts. So the circuit with the load is energized. Then
breaking the circuit would a similar case, as the moving contact will be
pulled up to the normally closed contacts under the force of the spring.
In this way, the switching on and off of the relay can control the state
of a load circuit.

.. image:: media/image143.png
    :align: center

Schematic Diagram:
-----------------------

.. image:: media/image144.png
    :align: center

Experimental Procedures
-----------------------

**Step 1:** Build the circuit.

.. image:: media/image145.png
    :align: center

For C Language Users:
^^^^^^^^^^^^^^^^^^^^^^^^^^

**Step 2**: Open the code file.

.. code-block:: 

    cd/home/pi/SunFounder_Super_Kit_V3.0_for_Raspberry_Pi/C

**Step 3:** Compile the Code.

.. code-block:: 

    make 07_relay

**Step 4:** Run the executable file above.

.. code-block:: 

    sudo ./07_relay

**Code Explanation**

.. code-block:: C

    digitalWrite(relayPin, LOW); /* Set the I/O port as LOW level (5V), thus
    the transistor is not energized and the coil is not powered. There is no
    electromagnetic force, so the relay opens.*/

    digitalWrite(relayPin, HIGH); /* set the I/O port as HIGH level (0V) to
    energize the transistor. The coil of the relay is powered and generate
    electromagnetic force, and the relay closes.*/

For Python Users:
^^^^^^^^^^^^^^^^^^^^^^

**Step 2:** Open the code file.

.. code-block:: 

    cd/home/pi/SunFounder_Super_Kit_V3.0_for_Raspberry_Pi/Python

**Step 3:** Run.

.. code-block:: 

    sudo python3 07_relay.py

**Code Explanation**

.. code-block:: python

    GPIO.output(relayPin, GPIO.LOW) 
    # Set the pins of the transistor as low level to let the relay open.

    time.sleep(1) # wait for 1 second. Change the switching frequency of the
    #relay by changing this parameter. Note: Relay is a kind of metal dome
    #formed in mechanical structure. So its lifespan will be shortened under
    #high-frequency using.

    GPIO.output(relayPin, GPIO.HIGH) 
    # Set the pins of transistor as HIGH level to actuate the relay.

    time.sleep(1)

Now, connect a device of high voltage, and the relay will close and the
LED will light up; connect one of low voltage, and it will open and the
LED will go out. In addition, you can hear a ticktock caused by breaking
normally close contact and closing normally open contact.

.. image:: media/image146.png
