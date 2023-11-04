# CompactPnP
### B4 size chip mounter for automatic mounting of chip components on printed circuit boards

Chip mounter for mounting SMD components on Printed Circuit Boards. Stencil fabrication is also possible by attaching a laser module. Using general-purpose and 3D-printed parts, and a Printed Circuit Board for the XZ axis, the machine is highly reproducible and compact.    

CompactPnPは、プリント基板にSMD部品を実装するB4サイズの小型チップマウンターです。100mm角程度のプリント基板へのSMTアセンブリを自動化できます。レーザーモジュールを装着することでステンシルフィルムの加工も可能。汎用部品と3Dプリント部品を使用し、XZ軸にはプリント基板を使用することで、高い再現性とコンパクト化を実現しています。

https://sites.google.com/view/nkpro

![Image 4 MakerFaireTokyo2023](https://makezine.jp/event/wp-content/uploads/sites/2/2023/08/CSO2OHAg.jpg)

Maker Faire Tokyo 2023
 https://makezine.jp/event/makers-mft2023/m0072/

Maker Faire Tokyo 2022
 https://makezine.jp/event/makers-mft2022/m0049/

＜マニュアル＞  
[CompactPnP Manual](manual/CPnPマニュアル3.pdf)  

＜箱の中＞  
* ノズルチップ付きヘッドx1
* ビジョンキャリブレーション用のTopカメラx1
* USB Type-C 20W PDアダプタ　＆ケーブル
* SMD部品搭載済みプリント基板（テスト済）
  * Main Board
  * Z-Board
  * Light for Top Camera
* Stepping Motor & Driver x4
* スルーホール部品 一式
* (Arduino) Pro Mega 2560 x1
* 加工済みアルミフレーム
  
＜おすすめオプション＞
* ビジョンキャリブレーション用のBottomカメラx1
* SMD部品搭載済みプリント基板（テスト済）
  * Light for Bottom Camera
* 磁石固定式ステージングプレート＆９０度固定ベース
* プーリー調整用8mm/10mmレンチ
  
＜レーザーオプション＞
* レーザーモジュール
* レーザー防護メガネ
* レーザー温度/LED電流表示用LCDパネル
  
＜技術仕様＞
| 項目 | 仕様 |
|:-----|-----------|
|最大PCBサイズ| 100mm x 180mm|
|搭載可能部品| 1608(0603)まで、高さ10mmまで、2グラムまで|
|配置速度|100 CPH（コンポーネントサイズと機械構成によって異なります）|
|機械の寸法|約40cm x 40cm x 16cm|
|消費電力|20W|
|制御ソフトウェア|OpenPnP|
|デバイスファームウェア|4軸grbl|
  
＜settings＞  
[Settings](Settings/.)


＜回路図＞  
[main board](schematics/ArduinoMegaCNC.pdf)  
[Z board](schematics/zaxis_rev05.pdf)  
[Light](schematics/CamLight.pdf)  

---
