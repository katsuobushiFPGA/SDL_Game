////////////////////////////!
//! \file
//! \brief Worldクラス
//!
//! ライフゲームの世界を表すクラスです。
//!
//! \author hiroto
//! \date 2015/08/25
///////////////////////////

class CWorld {
    public:
        CWorld();
        ~CWorld();
    public:
        init();
        addLife();
        isAlive();
        KillLife();
        nextStep();
}
