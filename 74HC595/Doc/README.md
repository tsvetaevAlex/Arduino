# Arduino
## Сдвиговый регистр 74hc595


| внешний вид |
|-------------|

<td align="left"> <img src="img\74hc595.png" alt="внешний вид Сдвигового регистра 74hc595"></td> |
| распиновка|
|<td><img src="img\74HC595_Pins_Size50.jpg" alt="распиновка Сдвигового регистра 74hc595"></td>

|Соответствие между выводами двигового регистра<br> и сегментами цифрово индикатора

| <img src="img\7segmetsUNducator_size50.png" alt="распиновка Сдвигового регистра 74hc595"> |
|-------------|
# bit order 
## MSBFIRST = Most Significant Bit First (старший бит передаётся первым.)

## Сегменты и цифры
### бит массивы для влючения сегментов на цифровом индикаторае
<table>
<tr>
  <td  colspan = "2"><B></B></td>
  <tr>
  <td> цифра
  </td>
  <td> бит массив 
  </td>   чччччч 
  </tr>
  <tr>
  <td align="center">
    1
  </td align="left">
  <td>
    B10010000
  </td>
  </tr>
  <tr>
  <td align="center">
    2
  </td align="left">
  <td>
    B ... 
  </td>
  </tr>
  <tr>
  <td align="center">
    3
  </td align="left">
  <td>
    B...
  </td>
  <tr>
  <td align="center">
    4
  </td align="left">
  <td>
    B...
  </td>
  </tr>
    <tr>
  <td align="center">
    5
  </td align="left">
  <td>
    B10010000
  </td>
  </tr>
  <tr>
  <td align="center">
    6
  </td align="left">
  <td>
    B ... 
  </td>
  </tr>
  <tr>
  <td align="center">
    7
  </td align="left">
  <td>
    B...
  </td>
  <tr>
  <td align="center">
    8
  </td align="left">
  <td>
    B...
  </td>
  </tr>
    </tr>
  <tr>
  <td align="center">
    9
  </td align="left">
  <td>
    B...
  </td>
  <tr>
  <td align="center">
    0
  </td align="left">
  <td>
    B...
  </td>
  </tr>
  </table>

  1 надо отправить массив : ```B10010000```

