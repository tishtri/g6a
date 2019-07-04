# g6a

Generator of Petri net models of hexagonal communication grid with plugs on edges


*Description:
------------

A composition of hexagonal grid is presented. There is a 2-dimensional hexagonal grid of size k on a plane. The model is composed of packet switching devices whose ports are situated
on sides of a unit-size equilateral hexagon. Each device works in full-duplex mode based on store-and-forward principle. Hexagons are connected via merging contact places situated on common sides. On the edges of hexagons, plug devices are attached. Hexagonal grids are widely applied in mobile networks.


Command line format:
--------------------

>g6a k [p] [b] > hx_model.ndr


Parameters:
-----------

k   size of hexagonal grid; 

p   the number of packets in each section of the internal buffer;

b   the available buffer size.

             
Output (file) format:
---------------------

.ndr  Petri nets graphical descriptions format according to http://www.laas.fr/tina


Tools to display, edit, visualize, and analyze generated models:
----------------------------------------------------------------

Tina Toolbox for analysis of Petri nets and Time Petri nets http://www.laas.fr/tina

Exported from Tina models are opened with other tools for Petri nets http://www.informatik.uni-hamburg.de/TGI/PetriNets /tools/quick.html


An example:
-----------

>g6a 4 1 0 > hx_k4p1b0.ndr

- Generate a model of a hexagonal grid with size 4, with 1 packet in each section of the internal buffer and available size of buffer 0.

>nd hx_k4p1b0.ndr

- The model is loaded into graphical environment of Tina. 

Menu: "Tools - stepper simulator - Rand"

- Watch the token game.


References:
-----------

Dmitry A. Zaitsev, Ivan D. Zaitsev and Tatiana R. Shmeleva. Infinite Petri Nets: Part 2, Modeling Triangular, Hexagonal, Hypercube and Hypertorus Structures, Complex Systems, 26(4), 2017, 341-371,  http://dx.doi.org/10.25088/ComplexSystems.26.4.341

Shmeleva T.R. Automated Composition of Petri Net Models for Cellular Structures. Transactions of IEEE First Ukraine Conference on Electrical and Computer Engineering, UKRCON 2017, May 29 – June 2, Kyiv, Ukraine, pp.1019-1024, doi:10.1109/UKRCON.2017.8100405,
https://ieeexplore.ieee.org/document/8100405                                                                 


----------------------------------------------------------
https://scholar.google.com.ua/citations?user=uuSbZDkAAAAJ
email: tishtri@rambler.ru
----------------------------------------------------------

