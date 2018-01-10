#pragma once

/// 状態
// ゲーム開始演出（キャラ登場～登場終了まで） 
#define STATE_BATTLE_START		0x0001
// キャラの行動選択を決定する
#define STATE_SELECT_COMMAND		0x0002
// バトル処理（行動順にキャラ行動を実行する）
#define STATE_BATTLE_ACTIVE		0x0003
// バトル終了（全滅or勝利演出を行う）
#define STATE_BATTLE_END			0x0004
// 必殺モード（コマンド入力とキャラ行動を即座に実行する）
#define STATE_SPECIAL_ACTIVE		0x0005
// 必殺モードの終了宣言（ダメージ結果演出などを行い、バトル終了判定へ）
#define STATE_SPECIAL_END		0x0006
// 現在持っているコマンドを解決する
#define STATE_COMMAND_ACTION		0x0007


// 攻撃コマンド
#define COMMAND_ATTACK			0x1001
// 防御コマンド
#define COMMAND_DEFENCE			0x1002
// 次のフェーズに移行する
//#define COMMAND_NEXT_PHASE		0x1003


