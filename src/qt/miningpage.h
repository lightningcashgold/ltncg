// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_MININGPAGE_H
#define BITCOIN_QT_MININGPAGE_H

#include <amount.h>

#include <QWidget>
#include <memory>

class ClientModel;
class TransactionFilterProxy;
class TxViewDelegateMining;
class PlatformStyle;
class WalletModel;

namespace Ui {
    class MiningPage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/**  ("home") page widget */
class MiningPage : public QWidget
{
    Q_OBJECT

public:
    explicit MiningPage(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~MiningPage();

    void setClientModel(ClientModel *_clientModel);
    void setModel(WalletModel *model);
    void setWalletModel(WalletModel *walletModel);
    void showOutOfSyncWarning(bool fShow);

public Q_SLOTS:
    void setBalance(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance,
                    const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance);

Q_SIGNALS:
    void transactionClicked(const QModelIndex &index);
    void beeButtonClicked();                    // LightningCash Gold: Hive
    void outOfSyncWarningClicked();

private:
    Ui::MiningPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    CAmount currentBalance;
    CAmount currentUnconfirmedBalance;
    CAmount currentImmatureBalance;
    CAmount currentWatchOnlyBalance;
    CAmount currentWatchUnconfBalance;
    CAmount currentWatchImmatureBalance;
    CAmount cost, rewardsPaid, profit;          // LightningCash Gold: Hive

    TxViewDelegateMining *txdelegate;
    std::unique_ptr<TransactionFilterProxy> filter;

private Q_SLOTS:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex &index);
    void updateAlerts(const QString &warnings);
    void updateWatchOnlyLabels(bool showWatchOnly);
    void handleOutOfSyncWarningClicks();
    void on_beeButton_clicked();                // LightningCash Gold: Hive: Bee button handler
    void updateHiveSummary();                   // LightningCash Gold: Hive: Update hive summary
};

#endif // BITCOIN_QT_MININGPAGE_H
