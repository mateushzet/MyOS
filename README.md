# MyOS
<small>I did the basics with this tutorial https://youtu.be/wz9CZBeXR6U, the input handling and system functionalities were done by myself.</small>
<h1>My 64-bit Operating System Kernel</h1>

Architecture: x86

Bootloader: multiboot2


<h2>Technologies used for creating environment and emulating os:</h2>

- Docker

- Qemu


<h2>Technologies installed in Docker container:</h2>

- <b>grub</b> (booting and loading os kernel and the bootloader)
- <b>xorriso</b> (creating and managing ISO image files)
- <b>nasm</b> (building asm object files)
- <b>gcc cross compiler</b> - "gcc-cross-x86_64-elf" (building c object files)


<h1>Process of emulating and launching os</h1>

1) Building containter image with docker - "docker build buildenv -t myos-buildenv"
  
  
2) Makeing instance of previous iamge - "docker run --rm -it -v ${PWD}:/root/env myos-buildenv"


4) Inside docker container generate the kernel.iso file by command "make build-x86_64"


6) Emulate the operating system using qemu command "qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso"


<h2>Scan Code mapping: </h2>


<table>
<thead>
  <tr>
    <th>0</th>
    <th>&nbsp;&nbsp;&nbsp;<br>' ',</th>
    <th>19</th>
    <th>'R',</th>
    <th>38</th>
    <th>'L',</th>
    <th>57</th>
    <th>' ',</th>
    <th>76</th>
    <th>' ',</th>
    <th>95</th>
    <th>' ',</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>1</td>
    <td>' ',</td>
    <td>20</td>
    <td>'T',</td>
    <td>39</td>
    <td>';',</td>
    <td>58</td>
    <td>' ',</td>
    <td>77</td>
    <td>' ',</td>
    <td>96</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>2</td>
    <td>'1',</td>
    <td>21</td>
    <td>'Y',</td>
    <td>40</td>
    <td>' ',</td>
    <td>59</td>
    <td>' ',</td>
    <td>78</td>
    <td>'+',</td>
    <td>97</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>3</td>
    <td>'2',</td>
    <td>22</td>
    <td>'U',</td>
    <td>41</td>
    <td>'`',</td>
    <td>60</td>
    <td>' ',</td>
    <td>79</td>
    <td>' ',</td>
    <td>98</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>4</td>
    <td>'3',</td>
    <td>23</td>
    <td>'I',</td>
    <td>42</td>
    <td>' ',</td>
    <td>61</td>
    <td>' ',</td>
    <td>80</td>
    <td>' ',</td>
    <td>99</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>5</td>
    <td>'4',</td>
    <td>24</td>
    <td>'O',</td>
    <td>43</td>
    <td>' ',</td>
    <td>62</td>
    <td>' ',</td>
    <td>81</td>
    <td>' ',</td>
    <td>100</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>6</td>
    <td>'5',</td>
    <td>25</td>
    <td>'P',</td>
    <td>44</td>
    <td>'Z',</td>
    <td>63</td>
    <td>' ',</td>
    <td>82</td>
    <td>' ',</td>
    <td>101</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>7</td>
    <td>'6',</td>
    <td>26</td>
    <td>'[',</td>
    <td>45</td>
    <td>'X',</td>
    <td>64</td>
    <td>' ',</td>
    <td>83</td>
    <td>' ',</td>
    <td>102</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>8</td>
    <td>'7',</td>
    <td>27</td>
    <td>']',</td>
    <td>46</td>
    <td>'C',</td>
    <td>65</td>
    <td>' ',</td>
    <td>84</td>
    <td>' ',</td>
    <td>103</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>9</td>
    <td>'8',</td>
    <td>28</td>
    <td>'\n',</td>
    <td>47</td>
    <td>'V',</td>
    <td>66</td>
    <td>' ',</td>
    <td>85</td>
    <td>' ',</td>
    <td>104</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>10</td>
    <td>'9',</td>
    <td>29</td>
    <td>' ',</td>
    <td>48</td>
    <td>'B',</td>
    <td>67</td>
    <td>' ',</td>
    <td>86</td>
    <td>' ',</td>
    <td>105</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>11</td>
    <td>'0',</td>
    <td>30</td>
    <td>'A',</td>
    <td>49</td>
    <td>'N',</td>
    <td>68</td>
    <td>' ',</td>
    <td>87</td>
    <td>' ',</td>
    <td>106</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>12</td>
    <td>'-',</td>
    <td>31</td>
    <td>'S',</td>
    <td>50</td>
    <td>'M',</td>
    <td>69</td>
    <td>' ',</td>
    <td>88</td>
    <td>' ',</td>
    <td>107</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>13</td>
    <td>'=',</td>
    <td>32</td>
    <td>'D',</td>
    <td>51</td>
    <td>',',</td>
    <td>70</td>
    <td>' ',</td>
    <td>89</td>
    <td>' ',</td>
    <td>108</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>14</td>
    <td>'\b',</td>
    <td>33</td>
    <td>'F',</td>
    <td>52</td>
    <td>'.',</td>
    <td>71</td>
    <td>' ',</td>
    <td>90</td>
    <td>' ',</td>
    <td>109</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>15</td>
    <td>' ',</td>
    <td>34</td>
    <td>'G',</td>
    <td>53</td>
    <td>'/',</td>
    <td>72</td>
    <td>' ',</td>
    <td>91</td>
    <td>' ',</td>
    <td>110</td>
    <td>' ',</td>
  </tr>
  <tr>
    <td>16</td>
    <td>'Q',</td>
    <td>35</td>
    <td>'H',</td>
    <td>54</td>
    <td>' ',</td>
    <td>73</td>
    <td>' ',</td>
    <td>92</td>
    <td>' ',</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>17</td>
    <td>'W',</td>
    <td>36</td>
    <td>'J',</td>
    <td>55</td>
    <td>' ',</td>
    <td>74</td>
    <td>'-',</td>
    <td>93</td>
    <td>' ',</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>18</td>
    <td>'E',</td>
    <td>37</td>
    <td>'K',</td>
    <td>56</td>
    <td>' ',</td>
    <td>75</td>
    <td>' ',</td>
    <td>94</td>
    <td>' ',</td>
    <td></td>
    <td></td>
  </tr>
</tbody>
</table>

<h2>Example on a real device</h2>
<img src =https://github.com/mateushzet/MyOS/blob/ec55c162626dba94c6611ca839cc2d8f793dd6b4/photo.jpg>
The system includes a text editor that stores data in RAM, a command line with a few commands that provide character animations and customization of menu text color, and a Tic-Tac-Toe game.
