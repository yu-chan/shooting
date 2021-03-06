![](./xy_gosanke.jpg)

## 概要
このリポジトリは就職活動で提出する作品を開発するために用意したものである

## 開発環境
IDEにはVisual Studio Community 2013を使用しています。

また、ライブラリはDXライブラリを用いています。

## 3Dモデルの変換方法
3Dモデルはxファイルを使う。

最初の変換方法はfbxはAutodesk FBX Converterを使ってobjに変換。

その後、objをオンラインでxに変換。

## 3Dの座標について
- X軸　　左:マイナス　右:プラス

- Y軸　　下:マイナス　上:プラス

- Z軸　手前:マイナス　奥:プラス

## 最優先事項 やるべきこと
Shotクラスのメモリの動的確保

当たり判定

BGM

データの読み込み

カメラワーク

ベクトルの勉強（向き、角度、大きさ、行列）

プレイヤーの向きに応じて、ショットの向きを変える

敵も同じように、変える

フィールド設定するかも...

フィールド内に敵をランダムに設定するかも...

時間が立つごとに敵が強くなるようにするかも...

スピード調整

shotのエラー対処

## 次にやるべきこと
モデルの作成・確保

モデルの描画処理の高速化

曲の確保

csvの作成(やめるかも...)

敵のランダム出現

## 参考文献
- [DXライブラリの置き場](http://dxlib.o.oo7.jp/)
- [無料で3Dモデルをダウンロードできる60のサイト | CG Campus ...](http://cgcampus.sitemix.jp/?p=312)
- [3DスペースシューティングをProcessingで作ろう - 遊んで航海記](http://eyln.hatenablog.com/entry/2015/12/18/223626)
- [3Dゲームの当たり判定 - Biglobe](http://www5f.biglobe.ne.jp/~kenmo/program/collision/3d/3d.html)
- [新・C言語 ～ゲームプログラミングの館～ [DXライブラリ]](http://dixq.net/g/)
- [サンプルプログラム　3Dアクション基本](http://dxlib.o.oo7.jp/program/dxprogram_3DAction.html)
- [龍神録プログラミングの館](http://dixq.net/rp/)
- [dxライブラリ隠し関数のページ - CCS Wiki](http://sherbet.transjiggen.com/ccs/ccs_wiki2/index.php?dx%A5%E9%A5%A4%A5%D6%A5%E9%A5%EA%B1%A3%A4%B7%B4%D8%BF%F4%A4%CE%A5%DA%A1%BC%A5%B8)
- [衝突判定 - RINEARN](http://www.rinearn.com/vcssl/graphics3d/intersection.shtml)