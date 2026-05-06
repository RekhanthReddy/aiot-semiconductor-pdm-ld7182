// XGBoost classifier exported via m2cgen
// AIoT PdM Semiconductor — Day 11 (5 May 2026)
// F1 = 0.3750, AUC ~ 0.73 on SECOM test set
// Top-100 features by RF importance, SMOTE 0.5, simpler hyperparameters

#ifndef XGB_MODEL_H
#define XGB_MODEL_H

#include <math.h>
#include <string.h>
double sigmoid(double x) {
    if (x < 0.0) {
        double z = exp(x);
        return z / (1.0 + z);
    }
    return 1.0 / (1.0 + exp(-x));
}
void score(double * input, double * output) {
    double var0;
    if (input[2] < -19274.832) {
        if (input[0] < -2331.481) {
            if (input[64] < -19736.842) {
                if (input[59] < -14935.076) {
                    var0 = 0.125;
                } else {
                    var0 = -0.1;
                }
            } else {
                if (input[25] < -3601.8335) {
                    var0 = -0.16782178;
                } else {
                    var0 = -0.043902438;
                }
            }
        } else {
            if (input[34] < 6945.4604) {
                if (input[52] < -12143.545) {
                    var0 = 0.11340206;
                } else {
                    var0 = -0.10243902;
                }
            } else {
                if (input[9] < -29042.566) {
                    var0 = -0.15918367;
                } else {
                    var0 = -0.016393444;
                }
            }
        }
    } else {
        if (input[33] < -28746.082) {
            if (input[98] < -1460.177) {
                if (input[78] < -26449.596) {
                    var0 = 0.02857143;
                } else {
                    var0 = -0.17142858;
                }
            } else {
                if (input[99] < -24143.377) {
                    var0 = 0.12592593;
                } else {
                    var0 = -0.09090909;
                }
            }
        } else {
            if (input[57] < -29177.506) {
                if (input[95] < -1829.5404) {
                    var0 = -0.13333334;
                } else {
                    var0 = 0.07692308;
                }
            } else {
                if (input[1] < -26472.135) {
                    var0 = -0.120000005;
                } else {
                    var0 = 0.14035088;
                }
            }
        }
    }
    double var1;
    if (input[2] < -19225.506) {
        if (input[25] < -1468.6207) {
            if (input[24] < 23799.9) {
                if (input[13] < 14304.201) {
                    var1 = -0.14565948;
                } else {
                    var1 = 0.0026517774;
                }
            } else {
                if (input[14] < 383.14175) {
                    var1 = -0.11738562;
                } else {
                    var1 = 0.16269398;
                }
            }
        } else {
            if (input[2] < -23200.006) {
                if (input[88] < 11684.591) {
                    var1 = 0.078928255;
                } else {
                    var1 = -0.1685302;
                }
            } else {
                if (input[32] < -29834.277) {
                    var1 = -0.05079303;
                } else {
                    var1 = 0.16554885;
                }
            }
        }
    } else {
        if (input[33] < -28891.674) {
            if (input[98] < -1460.177) {
                if (input[78] < -26449.596) {
                    var1 = 0.03143298;
                } else {
                    var1 = -0.15556362;
                }
            } else {
                if (input[99] < -21498.482) {
                    var1 = 0.09621823;
                } else {
                    var1 = -0.118369676;
                }
            }
        } else {
            if (input[57] < -29177.506) {
                if (input[95] < -2404.4365) {
                    var1 = -0.13590571;
                } else {
                    var1 = 0.054852236;
                }
            } else {
                if (input[1] < -26472.135) {
                    var1 = -0.10699888;
                } else {
                    var1 = 0.12780726;
                }
            }
        }
    }
    double var2;
    if (input[2] < -19366.414) {
        if (input[0] < -2331.481) {
            if (input[98] < -24690.266) {
                if (input[57] < -28549.11) {
                    var2 = -0.10701641;
                } else {
                    var2 = 0.10348517;
                }
            } else {
                if (input[54] < -26252.146) {
                    var2 = -0.14332552;
                } else {
                    var2 = -0.014091975;
                }
            }
        } else {
            if (input[34] < 7626.5825) {
                if (input[52] < -12143.545) {
                    var2 = 0.09421973;
                } else {
                    var2 = -0.08751705;
                }
            } else {
                if (input[11] < -2012.897) {
                    var2 = -0.12149606;
                } else {
                    var2 = 0.12758604;
                }
            }
        }
    } else {
        if (input[10] < 26427.996) {
            if (input[82] < -4521.9814) {
                if (input[7] < -29120.062) {
                    var2 = -0.06313544;
                } else {
                    var2 = 0.10728645;
                }
            } else {
                if (input[68] < -23741.465) {
                    var2 = -0.00029444313;
                } else {
                    var2 = -0.17338215;
                }
            }
        } else {
            if (input[85] < -26359.174) {
                var2 = -0.049381047;
            } else {
                var2 = -0.16345084;
            }
        }
    }
    double var3;
    if (input[2] < -19274.832) {
        if (input[25] < -3601.8335) {
            if (input[64] < -19736.842) {
                if (input[3] < -27473.438) {
                    var3 = 0.11640294;
                } else {
                    var3 = -0.0987717;
                }
            } else {
                if (input[13] < 14304.201) {
                    var3 = -0.13234758;
                } else {
                    var3 = 0.0065926197;
                }
            }
        } else {
            if (input[2] < -22865.918) {
                if (input[88] < 11684.591) {
                    var3 = 0.059256848;
                } else {
                    var3 = -0.14241274;
                }
            } else {
                if (input[31] < -17735.348) {
                    var3 = -0.11791623;
                } else {
                    var3 = 0.13625804;
                }
            }
        }
    } else {
        if (input[33] < -28891.674) {
            if (input[98] < -1460.177) {
                if (input[8] < -12515.591) {
                    var3 = -0.13877414;
                } else {
                    var3 = 0.049618676;
                }
            } else {
                if (input[89] < -13069.623) {
                    var3 = -0.060747206;
                } else {
                    var3 = 0.1242023;
                }
            }
        } else {
            if (input[37] < -13460.073) {
                var3 = -0.17804752;
            } else {
                if (input[46] < -6283.124) {
                    var3 = -0.009297292;
                } else {
                    var3 = 0.12026512;
                }
            }
        }
    }
    double var4;
    if (input[2] < -19366.414) {
        if (input[0] < -2331.481) {
            if (input[98] < -24690.266) {
                if (input[75] < -29942.984) {
                    var4 = -0.14222567;
                } else {
                    var4 = 0.06190868;
                }
            } else {
                if (input[77] < -17197.998) {
                    var4 = -0.13075577;
                } else {
                    var4 = -0.046232607;
                }
            }
        } else {
            if (input[34] < 7626.5825) {
                if (input[23] < -17517.19) {
                    var4 = 0.103135765;
                } else {
                    var4 = -0.045408722;
                }
            } else {
                if (input[11] < -2012.897) {
                    var4 = -0.10613918;
                } else {
                    var4 = 0.12599754;
                }
            }
        }
    } else {
        if (input[57] < -29033.32) {
            if (input[40] < -26341.363) {
                if (input[47] < -21101.244) {
                    var4 = 0.030038042;
                } else {
                    var4 = -0.1403544;
                }
            } else {
                var4 = -0.15858643;
            }
        } else {
            if (input[31] < -1777.182) {
                if (input[46] < -9001.919) {
                    var4 = -0.03927935;
                } else {
                    var4 = 0.11526841;
                }
            } else {
                if (input[33] < -13608.605) {
                    var4 = -0.11673447;
                } else {
                    var4 = 0.097369365;
                }
            }
        }
    }
    double var5;
    if (input[2] < -19225.506) {
        if (input[25] < -3601.8335) {
            if (input[64] < -19736.842) {
                if (input[3] < -27473.438) {
                    var5 = 0.104414664;
                } else {
                    var5 = -0.08697768;
                }
            } else {
                if (input[13] < 14304.201) {
                    var5 = -0.116751686;
                } else {
                    var5 = 0.009910789;
                }
            }
        } else {
            if (input[2] < -22865.918) {
                if (input[88] < 11684.591) {
                    var5 = 0.058849104;
                } else {
                    var5 = -0.12781246;
                }
            } else {
                if (input[57] < -29066.863) {
                    var5 = -0.115351155;
                } else {
                    var5 = 0.12720254;
                }
            }
        }
    } else {
        if (input[36] < -28453.84) {
            if (input[66] < -27049.18) {
                if (input[43] < -890.36945) {
                    var5 = -0.15406348;
                } else {
                    var5 = 0.10413625;
                }
            } else {
                var5 = 0.09602656;
            }
        } else {
            if (input[37] < -13460.073) {
                var5 = -0.16442601;
            } else {
                if (input[33] < -29067.334) {
                    var5 = -0.04077069;
                } else {
                    var5 = 0.09629553;
                }
            }
        }
    }
    double var6;
    if (input[2] < -19519.352) {
        if (input[11] < -19352.469) {
            if (input[31] < -6388.7515) {
                if (input[12] < -16156.633) {
                    var6 = 0.028255392;
                } else {
                    var6 = -0.12243467;
                }
            } else {
                if (input[59] < -12855.64) {
                    var6 = -0.020490851;
                } else {
                    var6 = -0.13870902;
                }
            }
        } else {
            if (input[60] < 5423.53) {
                if (input[49] < -26233.27) {
                    var6 = -0.083195835;
                } else {
                    var6 = 0.0929965;
                }
            } else {
                if (input[0] < -2949.5513) {
                    var6 = -0.025678534;
                } else {
                    var6 = -0.1360265;
                }
            }
        }
    } else {
        if (input[24] < -2459.0164) {
            if (input[63] < 1518.3699) {
                if (input[47] < -16172.291) {
                    var6 = -0.15950233;
                } else {
                    var6 = 0.004254294;
                }
            } else {
                var6 = 0.07646089;
            }
        } else {
            if (input[25] < -18529.338) {
                if (input[22] < -15397.014) {
                    var6 = -0.115374565;
                } else {
                    var6 = 0.047903024;
                }
            } else {
                if (input[37] < -13460.073) {
                    var6 = -0.13372086;
                } else {
                    var6 = 0.084299505;
                }
            }
        }
    }
    double var7;
    if (input[4] < -28100.523) {
        if (input[15] < -21590.908) {
            if (input[14] < 2681.9924) {
                if (input[9] < -28959.354) {
                    var7 = -0.12107321;
                } else {
                    var7 = 0.04688568;
                }
            } else {
                if (input[51] < -7073.3955) {
                    var7 = -0.08878792;
                } else {
                    var7 = 0.09318512;
                }
            }
        } else {
            if (input[11] < -8502.323) {
                if (input[25] < 7508.527) {
                    var7 = -0.13197874;
                } else {
                    var7 = 0.013081551;
                }
            } else {
                if (input[2] < -21373.834) {
                    var7 = -0.0836201;
                } else {
                    var7 = 0.10853117;
                }
            }
        }
    } else {
        if (input[10] < 26427.996) {
            if (input[80] < -5848.5103) {
                if (input[69] < -9082.402) {
                    var7 = -0.11154597;
                } else {
                    var7 = -0.0013504324;
                }
            } else {
                if (input[1] < -26426.78) {
                    var7 = -0.12546667;
                } else {
                    var7 = 0.08263864;
                }
            }
        } else {
            if (input[30] < -19356.223) {
                var7 = -0.13694547;
            } else {
                var7 = 0.020124057;
            }
        }
    }
    double var8;
    if (input[2] < -19915.088) {
        if (input[24] < 23799.9) {
            if (input[77] < -19316.014) {
                if (input[38] < 7165.9243) {
                    var8 = -0.10647166;
                } else {
                    var8 = 0.008966146;
                }
            } else {
                if (input[98] < -2654.8672) {
                    var8 = -0.10792214;
                } else {
                    var8 = 0.024941158;
                }
            }
        } else {
            if (input[14] < 383.14175) {
                var8 = -0.07529177;
            } else {
                if (input[53] < -27008.385) {
                    var8 = 0.13104507;
                } else {
                    var8 = 0.033511672;
                }
            }
        }
    } else {
        if (input[25] < -16725.246) {
            if (input[92] < -554.8914) {
                if (input[14] < 2697.8823) {
                    var8 = -0.10994083;
                } else {
                    var8 = 0.01703633;
                }
            } else {
                if (input[65] < -833.01636) {
                    var8 = -0.08396446;
                } else {
                    var8 = 0.16178052;
                }
            }
        } else {
            if (input[46] < -9001.919) {
                if (input[98] < -10340.264) {
                    var8 = 0.038284;
                } else {
                    var8 = -0.16333435;
                }
            } else {
                if (input[37] < -13460.073) {
                    var8 = -0.13184069;
                } else {
                    var8 = 0.09364865;
                }
            }
        }
    }
    double var9;
    if (input[4] < -28100.523) {
        if (input[15] < -21590.908) {
            if (input[56] < 13662.26) {
                if (input[38] < 8736.726) {
                    var9 = -0.12142519;
                } else {
                    var9 = 0.06458539;
                }
            } else {
                if (input[20] < 11681.99) {
                    var9 = 0.022354094;
                } else {
                    var9 = -0.1074846;
                }
            }
        } else {
            if (input[11] < -8502.323) {
                if (input[25] < 7508.527) {
                    var9 = -0.12228399;
                } else {
                    var9 = 0.016080437;
                }
            } else {
                if (input[2] < -21373.834) {
                    var9 = -0.07621103;
                } else {
                    var9 = 0.10140828;
                }
            }
        }
    } else {
        if (input[63] < -25542.275) {
            var9 = -0.13888673;
        } else {
            if (input[1] < -26426.78) {
                if (input[57] < -28475.328) {
                    var9 = -0.13983692;
                } else {
                    var9 = 0.013557612;
                }
            } else {
                if (input[10] < 26504.791) {
                    var9 = 0.056780774;
                } else {
                    var9 = -0.114661835;
                }
            }
        }
    }
    double var10;
    if (input[9] < -28967.188) {
        if (input[14] < 2298.8506) {
            if (input[92] < -554.8914) {
                if (input[70] < 28207.441) {
                    var10 = -0.10550276;
                } else {
                    var10 = 0.103683256;
                }
            } else {
                if (input[58] < -20913.906) {
                    var10 = 0.10457366;
                } else {
                    var10 = -0.10343102;
                }
            }
        } else {
            if (input[42] < -24603.756) {
                if (input[15] < -19318.182) {
                    var10 = 0.0804817;
                } else {
                    var10 = -0.116374135;
                }
            } else {
                if (input[0] < -8684.211) {
                    var10 = 0.07536393;
                } else {
                    var10 = -0.09785461;
                }
            }
        }
    } else {
        if (input[27] < -29344.227) {
            if (input[8] < -13725.366) {
                if (input[98] < 11347.097) {
                    var10 = -0.09542731;
                } else {
                    var10 = 0.051834483;
                }
            } else {
                if (input[42] < -26435.139) {
                    var10 = -0.078392595;
                } else {
                    var10 = 0.13008462;
                }
            }
        } else {
            if (input[10] < 25464.785) {
                if (input[57] < -29083.434) {
                    var10 = -0.06463795;
                } else {
                    var10 = 0.109087706;
                }
            } else {
                if (input[60] < 12356.495) {
                    var10 = -0.12339367;
                } else {
                    var10 = 0.09084522;
                }
            }
        }
    }
    double var11;
    if (input[2] < -19908.18) {
        if (input[6] < 5615.795) {
            if (input[76] < 3199.2405) {
                if (input[25] < 11270.527) {
                    var11 = -0.12731563;
                } else {
                    var11 = -0.014201596;
                }
            } else {
                if (input[89] < -21555.568) {
                    var11 = 0.11952084;
                } else {
                    var11 = -0.07826451;
                }
            }
        } else {
            if (input[54] < -26709.936) {
                if (input[33] < 14500.316) {
                    var11 = -0.09880426;
                } else {
                    var11 = 0.06247307;
                }
            } else {
                if (input[94] < -16122.742) {
                    var11 = -0.09302986;
                } else {
                    var11 = 0.033052143;
                }
            }
        }
    } else {
        if (input[25] < -16928.027) {
            if (input[22] < -15592.112) {
                if (input[92] < -554.8914) {
                    var11 = -0.10469138;
                } else {
                    var11 = 0.07365049;
                }
            } else {
                if (input[36] < -27918.174) {
                    var11 = -0.07343443;
                } else {
                    var11 = 0.06503885;
                }
            }
        } else {
            if (input[46] < -9001.919) {
                if (input[98] < -10340.264) {
                    var11 = 0.030948753;
                } else {
                    var11 = -0.14037165;
                }
            } else {
                if (input[55] < -27938.133) {
                    var11 = -0.007125894;
                } else {
                    var11 = 0.10043969;
                }
            }
        }
    }
    double var12;
    if (input[9] < -29186.352) {
        if (input[14] < 2298.8506) {
            if (input[70] < 28207.441) {
                if (input[33] < 20627.424) {
                    var12 = -0.11226608;
                } else {
                    var12 = 0.058541935;
                }
            } else {
                var12 = 0.088182144;
            }
        } else {
            if (input[35] < 17665.719) {
                if (input[42] < -24701.572) {
                    var12 = 0.021656532;
                } else {
                    var12 = -0.10224276;
                }
            } else {
                if (input[47] < -20841.969) {
                    var12 = 0.14166917;
                } else {
                    var12 = -0.03589954;
                }
            }
        }
    } else {
        if (input[3] < -28503.95) {
            if (input[6] < 23302.027) {
                if (input[53] < -24764.387) {
                    var12 = -0.12914892;
                } else {
                    var12 = -0.040376358;
                }
            } else {
                if (input[0] < 1653.5076) {
                    var12 = -0.017310007;
                } else {
                    var12 = 0.098129116;
                }
            }
        } else {
            if (input[68] < -17074.44) {
                if (input[10] < 25404.84) {
                    var12 = 0.05752349;
                } else {
                    var12 = -0.07763897;
                }
            } else {
                if (input[77] < -14100.363) {
                    var12 = -0.117879964;
                } else {
                    var12 = 0.039199907;
                }
            }
        }
    }
    double var13;
    if (input[4] < -28100.523) {
        if (input[15] < -21250.0) {
            if (input[5] < -28511.674) {
                if (input[35] < 19122.201) {
                    var13 = -0.119142406;
                } else {
                    var13 = 0.040251095;
                }
            } else {
                if (input[22] < -16448.73) {
                    var13 = -0.072268985;
                } else {
                    var13 = 0.030273795;
                }
            }
        } else {
            if (input[11] < -8502.323) {
                if (input[70] < 26981.791) {
                    var13 = -0.11479054;
                } else {
                    var13 = -0.003570087;
                }
            } else {
                if (input[13] < 6463.4346) {
                    var13 = -0.043270223;
                } else {
                    var13 = 0.10378528;
                }
            }
        }
    } else {
        if (input[80] < -8108.108) {
            if (input[98] < 132.74336) {
                if (input[88] < 18960.656) {
                    var13 = -0.12124168;
                } else {
                    var13 = 0.048833348;
                }
            } else {
                if (input[33] < -20096.049) {
                    var13 = 0.0986014;
                } else {
                    var13 = -0.116033316;
                }
            }
        } else {
            if (input[1] < -26426.78) {
                if (input[58] < -25798.072) {
                    var13 = -0.005147142;
                } else {
                    var13 = -0.12572262;
                }
            } else {
                if (input[83] < -26929.135) {
                    var13 = -0.12466725;
                } else {
                    var13 = 0.06229605;
                }
            }
        }
    }
    double var14;
    if (input[1] < -26403.361) {
        if (input[66] < -25662.043) {
            if (input[2] < -15559.0625) {
                if (input[88] < 9400.362) {
                    var14 = -0.022090485;
                } else {
                    var14 = -0.12478453;
                }
            } else {
                if (input[67] < -23280.81) {
                    var14 = 0.0742084;
                } else {
                    var14 = -0.09191683;
                }
            }
        } else {
            var14 = 0.10212894;
        }
    } else {
        if (input[9] < -28967.188) {
            if (input[34] < 8461.354) {
                if (input[6] < 3867.264) {
                    var14 = -0.116376616;
                } else {
                    var14 = 0.023554895;
                }
            } else {
                if (input[77] < -18927.4) {
                    var14 = -0.113220476;
                } else {
                    var14 = -0.02238444;
                }
            }
        } else {
            if (input[27] < -29344.227) {
                if (input[8] < -13855.752) {
                    var14 = -0.054039944;
                } else {
                    var14 = 0.09065179;
                }
            } else {
                if (input[39] < -26764.93) {
                    var14 = -0.09783403;
                } else {
                    var14 = 0.08692499;
                }
            }
        }
    }
    double var15;
    if (input[35] < -2142.5278) {
        if (input[97] < -23971.662) {
            if (input[58] < -20727.89) {
                if (input[51] < -12794.257) {
                    var15 = -0.03866482;
                } else {
                    var15 = 0.11821505;
                }
            } else {
                if (input[70] < -7770.5073) {
                    var15 = 0.03978705;
                } else {
                    var15 = -0.11787428;
                }
            }
        } else {
            if (input[54] < -26196.756) {
                if (input[34] < 17779.645) {
                    var15 = -0.11683641;
                } else {
                    var15 = 0.02650874;
                }
            } else {
                var15 = 0.02423594;
            }
        }
    } else {
        if (input[3] < -28640.625) {
            if (input[24] < 22657.52) {
                if (input[34] < 18269.322) {
                    var15 = -0.1253594;
                } else {
                    var15 = 0.0024625424;
                }
            } else {
                var15 = 0.08498527;
            }
        } else {
            if (input[80] < -4195.882) {
                if (input[64] < -13783.784) {
                    var15 = 0.04851973;
                } else {
                    var15 = -0.06019789;
                }
            } else {
                if (input[9] < -29404.018) {
                    var15 = -0.050109018;
                } else {
                    var15 = 0.061173376;
                }
            }
        }
    }
    double var16;
    if (input[1] < -26403.361) {
        if (input[66] < -25662.043) {
            if (input[2] < -15559.0625) {
                if (input[88] < 9400.362) {
                    var16 = -0.017758874;
                } else {
                    var16 = -0.1200815;
                }
            } else {
                if (input[58] < -24118.342) {
                    var16 = 0.06939119;
                } else {
                    var16 = -0.087545164;
                }
            }
        } else {
            var16 = 0.093831345;
        }
    } else {
        if (input[3] < -28640.625) {
            if (input[24] < 22657.52) {
                if (input[34] < 18924.629) {
                    var16 = -0.11890026;
                } else {
                    var16 = 0.05136034;
                }
            } else {
                var16 = 0.08189262;
            }
        } else {
            if (input[57] < -29083.434) {
                if (input[60] < 293.42773) {
                    var16 = 0.007038007;
                } else {
                    var16 = -0.09185939;
                }
            } else {
                if (input[49] < -27084.602) {
                    var16 = -0.07374843;
                } else {
                    var16 = 0.038665865;
                }
            }
        }
    }
    double var17;
    if (input[2] < -19908.18) {
        if (input[6] < 5615.795) {
            if (input[76] < 3199.2405) {
                if (input[25] < 11270.527) {
                    var17 = -0.11643503;
                } else {
                    var17 = -0.008028853;
                }
            } else {
                if (input[85] < 18381.514) {
                    var17 = -0.066312246;
                } else {
                    var17 = 0.11079704;
                }
            }
        } else {
            if (input[54] < -26765.607) {
                if (input[33] < 16509.21) {
                    var17 = -0.09590047;
                } else {
                    var17 = 0.07041676;
                }
            } else {
                if (input[49] < -26930.441) {
                    var17 = -0.10275062;
                } else {
                    var17 = 0.024537222;
                }
            }
        }
    } else {
        if (input[37] < -13460.073) {
            var17 = -0.13389844;
        } else {
            if (input[55] < -27597.703) {
                if (input[63] < -19633.25) {
                    var17 = -0.099373564;
                } else {
                    var17 = 0.028351778;
                }
            } else {
                if (input[69] < -2895.1223) {
                    var17 = 0.07696128;
                } else {
                    var17 = -0.07632583;
                }
            }
        }
    }
    double var18;
    if (input[1] < -26403.361) {
        if (input[66] < -25662.043) {
            if (input[2] < -15559.0625) {
                if (input[54] < -26171.838) {
                    var18 = -0.1163911;
                } else {
                    var18 = -0.018334938;
                }
            } else {
                if (input[67] < -23280.81) {
                    var18 = 0.065106176;
                } else {
                    var18 = -0.084827;
                }
            }
        } else {
            var18 = 0.08812953;
        }
    } else {
        if (input[13] < -12299.183) {
            if (input[63] < 16088.614) {
                if (input[32] < -29235.324) {
                    var18 = -0.11624247;
                } else {
                    var18 = -0.010233729;
                }
            } else {
                var18 = 0.023820005;
            }
        } else {
            if (input[10] < 25736.854) {
                if (input[41] < -14718.473) {
                    var18 = -0.046260044;
                } else {
                    var18 = 0.038443353;
                }
            } else {
                if (input[89] < -14178.886) {
                    var18 = -0.109492004;
                } else {
                    var18 = 0.012680545;
                }
            }
        }
    }
    double var19;
    if (input[35] < -2142.5278) {
        if (input[97] < -23971.662) {
            if (input[58] < -20727.89) {
                if (input[92] < -14316.248) {
                    var19 = -0.08393757;
                } else {
                    var19 = 0.08144065;
                }
            } else {
                if (input[70] < -7770.5073) {
                    var19 = 0.038395703;
                } else {
                    var19 = -0.1109784;
                }
            }
        } else {
            if (input[54] < -26196.756) {
                if (input[39] < -24243.838) {
                    var19 = -0.11597689;
                } else {
                    var19 = -0.030956341;
                }
            } else {
                var19 = 0.0265647;
            }
        }
    } else {
        if (input[81] < -10098.28) {
            if (input[65] < -12586.535) {
                if (input[49] < -27712.385) {
                    var19 = -0.03092419;
                } else {
                    var19 = -0.12345233;
                }
            } else {
                if (input[1] < -26403.361) {
                    var19 = -0.09342006;
                } else {
                    var19 = 0.05220396;
                }
            }
        } else {
            if (input[8] < -14884.404) {
                if (input[74] < -26780.281) {
                    var19 = 0.0388333;
                } else {
                    var19 = -0.080010824;
                }
            } else {
                if (input[19] < -14165.999) {
                    var19 = -0.11678642;
                } else {
                    var19 = 0.08227456;
                }
            }
        }
    }
    double var20;
    if (input[3] < -28503.95) {
        if (input[64] < -20907.293) {
            var20 = 0.09018303;
        } else {
            if (input[0] < 3127.9224) {
                if (input[74] < -17875.879) {
                    var20 = -0.112194695;
                } else {
                    var20 = -0.031472117;
                }
            } else {
                var20 = 0.06338361;
            }
        }
    } else {
        if (input[7] < -28933.123) {
            if (input[14] < 2298.8506) {
                if (input[70] < 28207.441) {
                    var20 = -0.084119216;
                } else {
                    var20 = 0.1121817;
                }
            } else {
                if (input[35] < 17665.719) {
                    var20 = -0.020477686;
                } else {
                    var20 = 0.117086984;
                }
            }
        } else {
            if (input[10] < 25982.594) {
                if (input[68] < -16771.73) {
                    var20 = 0.045086246;
                } else {
                    var20 = -0.09252109;
                }
            } else {
                if (input[60] < 13171.433) {
                    var20 = -0.10366353;
                } else {
                    var20 = 0.060617108;
                }
            }
        }
    }
    double var21;
    if (input[4] < -28422.746) {
        if (input[40] < -26509.707) {
            if (input[90] < -26439.498) {
                var21 = 0.0028968109;
            } else {
                if (input[26] < -28273.953) {
                    var21 = -0.022136984;
                } else {
                    var21 = -0.11646483;
                }
            }
        } else {
            if (input[39] < -25265.008) {
                var21 = -0.10156294;
            } else {
                if (input[59] < -15476.617) {
                    var21 = 0.11222345;
                } else {
                    var21 = -0.027826024;
                }
            }
        }
    } else {
        if (input[1] < -26426.78) {
            if (input[66] < -25662.043) {
                if (input[2] < -15559.0625) {
                    var21 = -0.11252471;
                } else {
                    var21 = -0.009866153;
                }
            } else {
                var21 = 0.078764156;
            }
        } else {
            if (input[21] < -10693.571) {
                if (input[10] < 26504.791) {
                    var21 = 0.02583072;
                } else {
                    var21 = -0.101749316;
                }
            } else {
                if (input[55] < -25941.852) {
                    var21 = -0.11175155;
                } else {
                    var21 = 0.08350732;
                }
            }
        }
    }
    double var22;
    if (input[3] < -28640.625) {
        if (input[24] < 22657.52) {
            if (input[34] < 18924.629) {
                if (input[80] < -17956.082) {
                    var22 = -0.0150092365;
                } else {
                    var22 = -0.114681065;
                }
            } else {
                var22 = 0.048147302;
            }
        } else {
            var22 = 0.07312481;
        }
    } else {
        if (input[39] < -26281.27) {
            if (input[63] < 848.3366) {
                if (input[13] < 7434.7725) {
                    var22 = -0.10921552;
                } else {
                    var22 = -0.0049418076;
                }
            } else {
                if (input[65] < 1202.5433) {
                    var22 = -0.09046389;
                } else {
                    var22 = 0.07665738;
                }
            }
        } else {
            if (input[49] < -26999.605) {
                if (input[89] < -15032.762) {
                    var22 = -0.10032163;
                } else {
                    var22 = 0.035558674;
                }
            } else {
                if (input[32] < -29682.867) {
                    var22 = -0.0026292508;
                } else {
                    var22 = 0.068400994;
                }
            }
        }
    }
    double var23;
    if (input[4] < -28422.746) {
        if (input[40] < -26509.707) {
            if (input[90] < -26439.498) {
                var23 = 0.0005481437;
            } else {
                if (input[26] < -28273.953) {
                    var23 = -0.018836727;
                } else {
                    var23 = -0.11323076;
                }
            }
        } else {
            if (input[39] < -25265.008) {
                var23 = -0.09851276;
            } else {
                if (input[59] < -15476.617) {
                    var23 = 0.10412854;
                } else {
                    var23 = -0.028188307;
                }
            }
        }
    } else {
        if (input[1] < -26426.78) {
            if (input[66] < -25662.043) {
                if (input[2] < -15559.0625) {
                    var23 = -0.109688856;
                } else {
                    var23 = -0.0077959555;
                }
            } else {
                var23 = 0.07583691;
            }
        } else {
            if (input[55] < -28654.81) {
                if (input[34] < 14482.19) {
                    var23 = -0.10834616;
                } else {
                    var23 = 0.048944943;
                }
            } else {
                if (input[80] < -5836.1484) {
                    var23 = -0.024895532;
                } else {
                    var23 = 0.03929295;
                }
            }
        }
    }
    double var24;
    if (input[82] < -3120.743) {
        if (input[63] < -25542.275) {
            if (input[64] < -23492.176) {
                if (input[55] < -27224.912) {
                    var24 = -0.049030427;
                } else {
                    var24 = 0.09792603;
                }
            } else {
                if (input[76] < 3647.613) {
                    var24 = -0.114545755;
                } else {
                    var24 = 0.03850702;
                }
            }
        } else {
            if (input[6] < 995.71594) {
                if (input[7] < -27822.816) {
                    var24 = -0.110104755;
                } else {
                    var24 = -0.0045242305;
                }
            } else {
                if (input[21] < -10693.571) {
                    var24 = 0.028015992;
                } else {
                    var24 = -0.09820429;
                }
            }
        }
    } else {
        if (input[14] < 5951.162) {
            if (input[85] < 17748.809) {
                var24 = -0.12459687;
            } else {
                if (input[76] < 840.03485) {
                    var24 = -0.081630446;
                } else {
                    var24 = 0.0698233;
                }
            }
        } else {
            if (input[70] < 23658.928) {
                if (input[67] < -22337.168) {
                    var24 = 0.014519681;
                } else {
                    var24 = 0.14070973;
                }
            } else {
                var24 = -0.09015497;
            }
        }
    }
    double var25;
    if (input[13] < -12299.183) {
        if (input[38] < -14022.884) {
            var25 = 0.027736446;
        } else {
            if (input[63] < 13342.548) {
                var25 = -0.11072799;
            } else {
                var25 = -0.01186126;
            }
        }
    } else {
        if (input[39] < -26281.27) {
            if (input[65] < -1947.1766) {
                if (input[82] < -14747.368) {
                    var25 = -0.021107933;
                } else {
                    var25 = -0.11324511;
                }
            } else {
                if (input[9] < -29259.732) {
                    var25 = -0.08784786;
                } else {
                    var25 = 0.023073833;
                }
            }
        } else {
            if (input[49] < -26999.605) {
                if (input[89] < -15032.762) {
                    var25 = -0.0993511;
                } else {
                    var25 = 0.03621495;
                }
            } else {
                if (input[10] < 25982.594) {
                    var25 = 0.03776171;
                } else {
                    var25 = -0.07665592;
                }
            }
        }
    }
    double var26;
    if (input[73] < 3176.7595) {
        if (input[98] < -25359.22) {
            var26 = 0.02614688;
        } else {
            if (input[12] < -16552.396) {
                var26 = 0.034123566;
            } else {
                if (input[74] < -26969.97) {
                    var26 = -0.029002344;
                } else {
                    var26 = -0.11710818;
                }
            }
        }
    } else {
        if (input[3] < -28640.625) {
            if (input[6] < 25953.041) {
                if (input[64] < -18029.871) {
                    var26 = 0.028347606;
                } else {
                    var26 = -0.106984735;
                }
            } else {
                var26 = 0.04973939;
            }
        } else {
            if (input[55] < -28291.83) {
                if (input[70] < 21753.064) {
                    var26 = -0.006240049;
                } else {
                    var26 = -0.098482214;
                }
            } else {
                if (input[82] < -3120.743) {
                    var26 = 0.031313706;
                } else {
                    var26 = -0.07631431;
                }
            }
        }
    }
    double var27;
    if (input[4] < -28422.746) {
        if (input[40] < -26509.707) {
            if (input[90] < -26439.498) {
                var27 = -0.0005613218;
            } else {
                if (input[88] < 9851.297) {
                    var27 = -0.018070607;
                } else {
                    var27 = -0.10945028;
                }
            }
        } else {
            if (input[39] < -25265.008) {
                var27 = -0.09584285;
            } else {
                if (input[85] < 4789.735) {
                    var27 = 0.10760229;
                } else {
                    var27 = -0.0032125593;
                }
            }
        }
    } else {
        if (input[35] < -2142.5278) {
            if (input[97] < -23971.662) {
                if (input[58] < -20727.89) {
                    var27 = 0.071395755;
                } else {
                    var27 = -0.061670046;
                }
            } else {
                if (input[54] < -26196.756) {
                    var27 = -0.102891766;
                } else {
                    var27 = 0.047885787;
                }
            }
        } else {
            if (input[22] < -16322.156) {
                if (input[76] < -5021.614) {
                    var27 = 0.008574709;
                } else {
                    var27 = -0.08348533;
                }
            } else {
                if (input[49] < -27638.96) {
                    var27 = -0.09366981;
                } else {
                    var27 = 0.048862044;
                }
            }
        }
    }
    double var28;
    if (input[69] < -751.58466) {
        if (input[1] < -26403.361) {
            if (input[99] < -25072.078) {
                if (input[99] < -25618.361) {
                    var28 = -0.06338556;
                } else {
                    var28 = 0.058541607;
                }
            } else {
                var28 = -0.10736581;
            }
        } else {
            if (input[94] < 1340.8655) {
                if (input[83] < -26929.135) {
                    var28 = -0.11273165;
                } else {
                    var28 = 0.024994671;
                }
            } else {
                if (input[86] < 9397.785) {
                    var28 = -0.11298436;
                } else {
                    var28 = -0.009824989;
                }
            }
        }
    } else {
        if (input[70] < -19699.475) {
            if (input[93] < -22705.035) {
                var28 = -0.09909201;
            } else {
                if (input[72] < -29109.135) {
                    var28 = -0.03254511;
                } else {
                    var28 = 0.115884006;
                }
            }
        } else {
            if (input[93] < -27985.611) {
                var28 = 0.020944145;
            } else {
                var28 = -0.1170874;
            }
        }
    }
    double var29;
    if (input[93] < -24460.432) {
        if (input[59] < -15508.011) {
            if (input[64] < -341.394) {
                if (input[1] < -25832.426) {
                    var29 = -0.07803936;
                } else {
                    var29 = 0.07482013;
                }
            } else {
                if (input[72] < -28359.494) {
                    var29 = -0.10466804;
                } else {
                    var29 = 0.023320096;
                }
            }
        } else {
            if (input[13] < 13948.573) {
                if (input[87] < -28357.236) {
                    var29 = 0.053148713;
                } else {
                    var29 = -0.09906756;
                }
            } else {
                if (input[63] < 3452.9365) {
                    var29 = -0.072179176;
                } else {
                    var29 = 0.1124689;
                }
            }
        }
    } else {
        if (input[45] < -28929.9) {
            if (input[13] < 7434.7725) {
                if (input[4] < -25600.111) {
                    var29 = -0.11185589;
                } else {
                    var29 = -0.025925372;
                }
            } else {
                if (input[13] < 11613.259) {
                    var29 = 0.055762645;
                } else {
                    var29 = -0.09122377;
                }
            }
        } else {
            if (input[9] < -29404.018) {
                if (input[14] < 5517.241) {
                    var29 = -0.06283286;
                } else {
                    var29 = 0.054722484;
                }
            } else {
                if (input[80] < -10954.284) {
                    var29 = -0.047278367;
                } else {
                    var29 = 0.054540314;
                }
            }
        }
    }
    double var30;
    if (input[59] < -14153.212) {
        if (input[41] < -10805.689) {
            if (input[52] < -6500.2524) {
                if (input[4] < -26032.012) {
                    var30 = -0.08880485;
                } else {
                    var30 = 0.017302107;
                }
            } else {
                if (input[79] < -28532.104) {
                    var30 = 0.121322416;
                } else {
                    var30 = -0.057525437;
                }
            }
        } else {
            if (input[23] < -10932.009) {
                if (input[94] < -4399.64) {
                    var30 = 0.059371628;
                } else {
                    var30 = -0.031393778;
                }
            } else {
                var30 = -0.09953796;
            }
        }
    } else {
        if (input[46] < -3427.8955) {
            if (input[38] < 4.7085695) {
                if (input[10] < -4572.515) {
                    var30 = -0.0012233373;
                } else {
                    var30 = -0.111491285;
                }
            } else {
                if (input[62] < -29974.824) {
                    var30 = -0.07501149;
                } else {
                    var30 = 0.055765297;
                }
            }
        } else {
            if (input[43] < -7496.926) {
                if (input[52] < -14395.203) {
                    var30 = 0.02062894;
                } else {
                    var30 = -0.07159123;
                }
            } else {
                if (input[37] < -12253.817) {
                    var30 = -0.07010879;
                } else {
                    var30 = 0.08863564;
                }
            }
        }
    }
    double var31;
    if (input[4] < -28422.746) {
        if (input[40] < -26509.707) {
            if (input[76] < -18573.268) {
                var31 = 0.0018454151;
            } else {
                if (input[88] < 9973.256) {
                    var31 = -0.016481992;
                } else {
                    var31 = -0.105941236;
                }
            }
        } else {
            if (input[39] < -25265.008) {
                var31 = -0.09294547;
            } else {
                if (input[53] < -27161.95) {
                    var31 = -0.023195503;
                } else {
                    var31 = 0.089921795;
                }
            }
        }
    } else {
        if (input[83] < -26209.514) {
            if (input[60] < -3026.1145) {
                if (input[38] < -10368.886) {
                    var31 = 0.06845985;
                } else {
                    var31 = -0.04109024;
                }
            } else {
                var31 = -0.11806347;
            }
        } else {
            if (input[46] < -3742.8022) {
                if (input[78] < -20696.338) {
                    var31 = 0.002075402;
                } else {
                    var31 = -0.08216066;
                }
            } else {
                if (input[55] < -28672.895) {
                    var31 = -0.10491997;
                } else {
                    var31 = 0.036383282;
                }
            }
        }
    }
    double var32;
    if (input[13] < -12299.183) {
        if (input[71] < -16392.102) {
            var32 = -0.1053948;
        } else {
            if (input[7] < -29354.209) {
                var32 = 0.071479544;
            } else {
                var32 = -0.06634088;
            }
        }
    } else {
        if (input[59] < -13279.018) {
            if (input[41] < -11540.1875) {
                if (input[50] < 1047.4113) {
                    var32 = 0.011556543;
                } else {
                    var32 = -0.08532661;
                }
            } else {
                if (input[23] < -10932.009) {
                    var32 = 0.047190834;
                } else {
                    var32 = -0.0943973;
                }
            }
        } else {
            if (input[89] < -21733.932) {
                if (input[57] < -27931.559) {
                    var32 = -0.089210354;
                } else {
                    var32 = 0.068194196;
                }
            } else {
                if (input[19] < -8083.927) {
                    var32 = 0.020559764;
                } else {
                    var32 = -0.103276566;
                }
            }
        }
    }
    double var33;
    if (input[93] < -24460.432) {
        if (input[34] < 7449.2705) {
            if (input[78] < -19385.703) {
                if (input[53] < -26288.049) {
                    var33 = 0.05034106;
                } else {
                    var33 = -0.06749742;
                }
            } else {
                if (input[81] < -13905.465) {
                    var33 = -0.023401374;
                } else {
                    var33 = -0.10401311;
                }
            }
        } else {
            if (input[27] < -29344.227) {
                if (input[57] < -27931.559) {
                    var33 = -0.113105536;
                } else {
                    var33 = -0.013067198;
                }
            } else {
                if (input[39] < -25637.627) {
                    var33 = 0.040044572;
                } else {
                    var33 = -0.093987666;
                }
            }
        }
    } else {
        if (input[45] < -28929.9) {
            if (input[13] < 7434.7725) {
                if (input[4] < -25600.111) {
                    var33 = -0.10819942;
                } else {
                    var33 = -0.02419901;
                }
            } else {
                if (input[13] < 11613.259) {
                    var33 = 0.049316425;
                } else {
                    var33 = -0.087444685;
                }
            }
        } else {
            if (input[83] < -26220.473) {
                var33 = -0.10727066;
            } else {
                if (input[73] < 2780.8364) {
                    var33 = -0.08312368;
                } else {
                    var33 = 0.03870782;
                }
            }
        }
    }
    double var34;
    if (input[69] < -751.58466) {
        if (input[1] < -26403.361) {
            if (input[99] < -25072.078) {
                if (input[70] < 24622.488) {
                    var34 = 0.03722469;
                } else {
                    var34 = -0.07134341;
                }
            } else {
                var34 = -0.10340186;
            }
        } else {
            if (input[13] < -12299.183) {
                if (input[83] < -13808.544) {
                    var34 = -0.10227033;
                } else {
                    var34 = 0.01554005;
                }
            } else {
                if (input[31] < -278.16904) {
                    var34 = 0.023893712;
                } else {
                    var34 = -0.08429717;
                }
            }
        }
    } else {
        if (input[70] < -19699.475) {
            if (input[93] < -22705.035) {
                var34 = -0.091592275;
            } else {
                if (input[72] < -29103.355) {
                    var34 = -0.025882859;
                } else {
                    var34 = 0.10436829;
                }
            }
        } else {
            if (input[93] < -27899.281) {
                var34 = 0.02059641;
            } else {
                var34 = -0.11269547;
            }
        }
    }
    double var35;
    if (input[89] < -24917.01) {
        if (input[19] < -8854.306) {
            var35 = -0.11707305;
        } else {
            if (input[86] < 5282.9087) {
                if (input[94] < -6553.3276) {
                    var35 = 0.07742443;
                } else {
                    var35 = -0.05433261;
                }
            } else {
                if (input[63] < -313.78864) {
                    var35 = -0.10262277;
                } else {
                    var35 = -0.01962914;
                }
            }
        }
    } else {
        if (input[80] < -8557.976) {
            if (input[36] < -27549.521) {
                if (input[40] < -29147.5) {
                    var35 = 0.005285032;
                } else {
                    var35 = -0.10578413;
                }
            } else {
                if (input[33] < -14471.208) {
                    var35 = -0.0474792;
                } else {
                    var35 = 0.104798436;
                }
            }
        } else {
            if (input[82] < -2869.969) {
                if (input[68] < -17470.855) {
                    var35 = 0.0407246;
                } else {
                    var35 = -0.052993514;
                }
            } else {
                if (input[85] < 17748.809) {
                    var35 = -0.10967237;
                } else {
                    var35 = 0.020670831;
                }
            }
        }
    }
    double var36;
    if (input[3] < -28640.625) {
        if (input[24] < 22657.52) {
            if (input[38] < -12389.783) {
                var36 = 0.023483304;
            } else {
                var36 = -0.10460826;
            }
        } else {
            var36 = 0.06321037;
        }
    } else {
        if (input[10] < 26504.791) {
            if (input[73] < 3176.7595) {
                if (input[12] < -15065.278) {
                    var36 = 0.028872048;
                } else {
                    var36 = -0.09590669;
                }
            } else {
                if (input[69] < 721.4006) {
                    var36 = 0.02121171;
                } else {
                    var36 = -0.0743347;
                }
            }
        } else {
            if (input[3] < -24529.688) {
                var36 = -0.102111556;
            } else {
                var36 = 0.020235786;
            }
        }
    }
    double var37;
    if (input[4] < -28422.746) {
        if (input[76] < -18573.268) {
            if (input[68] < -20943.398) {
                var37 = -0.03544445;
            } else {
                var37 = 0.08603007;
            }
        } else {
            if (input[64] < -11479.374) {
                if (input[40] < -27233.547) {
                    var37 = -0.08230838;
                } else {
                    var37 = 0.087849356;
                }
            } else {
                var37 = -0.10794713;
            }
        }
    } else {
        if (input[94] < 1340.8655) {
            if (input[41] < -15668.82) {
                if (input[81] < -11572.481) {
                    var37 = 0.006670793;
                } else {
                    var37 = -0.1088511;
                }
            } else {
                if (input[74] < -20650.705) {
                    var37 = 0.033782594;
                } else {
                    var37 = -0.055731814;
                }
            }
        } else {
            if (input[66] < -28726.355) {
                if (input[77] < -24733.879) {
                    var37 = 0.07123232;
                } else {
                    var37 = -0.06872392;
                }
            } else {
                if (input[35] < 14859.631) {
                    var37 = -0.11949419;
                } else {
                    var37 = 0.021279437;
                }
            }
        }
    }
    double var38;
    if (input[1] < -26403.361) {
        if (input[66] < -25662.043) {
            if (input[96] < -2100.5803) {
                if (input[87] < -15684.485) {
                    var38 = -0.05845937;
                } else {
                    var38 = 0.052821785;
                }
            } else {
                if (input[71] < -26964.074) {
                    var38 = -0.00669215;
                } else {
                    var38 = -0.104114704;
                }
            }
        } else {
            var38 = 0.06200552;
        }
    } else {
        if (input[81] < -10098.28) {
            if (input[19] < -4463.39) {
                if (input[35] < -2142.5278) {
                    var38 = -0.03483936;
                } else {
                    var38 = 0.04647551;
                }
            } else {
                if (input[43] < -12060.469) {
                    var38 = -0.11502447;
                } else {
                    var38 = -0.0030948175;
                }
            }
        } else {
            if (input[27] < -29171.928) {
                if (input[8] < -12515.591) {
                    var38 = -0.07304533;
                } else {
                    var38 = 0.048014462;
                }
            } else {
                if (input[57] < -28766.502) {
                    var38 = -0.037725575;
                } else {
                    var38 = 0.06264093;
                }
            }
        }
    }
    double var39;
    if (input[89] < -23831.863) {
        if (input[41] < -10805.689) {
            var39 = -0.11306701;
        } else {
            if (input[22] < -15869.87) {
                if (input[25] < -2162.837) {
                    var39 = -0.08947827;
                } else {
                    var39 = 0.054650005;
                }
            } else {
                if (input[94] < -7523.12) {
                    var39 = 0.090837754;
                } else {
                    var39 = -0.050184995;
                }
            }
        }
    } else {
        if (input[58] < -20775.312) {
            if (input[83] < -26209.514) {
                if (input[26] < -26083.227) {
                    var39 = -0.02762873;
                } else {
                    var39 = -0.10295822;
                }
            } else {
                if (input[70] < -13447.498) {
                    var39 = -0.059213765;
                } else {
                    var39 = 0.044713248;
                }
            }
        } else {
            if (input[70] < 11451.4795) {
                if (input[74] < -23977.465) {
                    var39 = 0.08059376;
                } else {
                    var39 = -0.0790222;
                }
            } else {
                if (input[33] < -7787.0337) {
                    var39 = -0.08597063;
                } else {
                    var39 = 0.012745445;
                }
            }
        }
    }
    double var40;
    if (input[6] < 995.71594) {
        if (input[7] < -27822.816) {
            var40 = -0.10161015;
        } else {
            var40 = 0.025135292;
        }
    } else {
        if (input[63] < -25542.275) {
            if (input[6] < 23686.232) {
                if (input[24] < 20406.3) {
                    var40 = -0.11273016;
                } else {
                    var40 = 0.03665767;
                }
            } else {
                if (input[62] < -29986.611) {
                    var40 = -0.059648383;
                } else {
                    var40 = 0.09331959;
                }
            }
        } else {
            if (input[82] < -4521.9814) {
                if (input[88] < 18083.816) {
                    var40 = 0.028000394;
                } else {
                    var40 = -0.07308353;
                }
            } else {
                if (input[43] < -17970.926) {
                    var40 = 0.02671125;
                } else {
                    var40 = -0.08822236;
                }
            }
        }
    }
    double var41;
    if (input[93] < -24460.432) {
        if (input[34] < 7626.5825) {
            if (input[45] < -27420.75) {
                if (input[54] < -26709.936) {
                    var41 = -0.045763034;
                } else {
                    var41 = 0.05706082;
                }
            } else {
                var41 = -0.09504533;
            }
        } else {
            if (input[27] < -29313.531) {
                if (input[91] < -27826.08) {
                    var41 = -0.1123934;
                } else {
                    var41 = -0.014515576;
                }
            } else {
                if (input[57] < -28874.91) {
                    var41 = -0.09467248;
                } else {
                    var41 = 0.04147406;
                }
            }
        }
    } else {
        if (input[45] < -28961.295) {
            if (input[13] < 7434.7725) {
                if (input[4] < -25600.111) {
                    var41 = -0.10602573;
                } else {
                    var41 = -0.024186796;
                }
            } else {
                if (input[72] < -29071.21) {
                    var41 = 0.053847022;
                } else {
                    var41 = -0.08267509;
                }
            }
        } else {
            if (input[83] < -26220.473) {
                var41 = -0.10019322;
            } else {
                if (input[57] < -29011.17) {
                    var41 = -0.014674808;
                } else {
                    var41 = 0.045583375;
                }
            }
        }
    }
    double var42;
    if (input[1] < -26403.361) {
        if (input[66] < -25662.043) {
            if (input[96] < -2100.5803) {
                var42 = -0.0072198524;
            } else {
                if (input[56] < 23213.996) {
                    var42 = -0.10200619;
                } else {
                    var42 = -0.011983107;
                }
            }
        } else {
            var42 = 0.056409217;
        }
    } else {
        if (input[42] < -23175.566) {
            if (input[13] < -12299.183) {
                if (input[78] < -17638.191) {
                    var42 = -0.094087854;
                } else {
                    var42 = -0.022915512;
                }
            } else {
                if (input[10] < 25736.854) {
                    var42 = 0.028334618;
                } else {
                    var42 = -0.06860912;
                }
            }
        } else {
            if (input[72] < -28789.744) {
                if (input[30] < -20987.125) {
                    var42 = -0.094996326;
                } else {
                    var42 = 0.040411305;
                }
            } else {
                if (input[58] < -22816.82) {
                    var42 = -0.08462452;
                } else {
                    var42 = 0.05526359;
                }
            }
        }
    }
    double var43;
    if (input[59] < -13308.458) {
        if (input[21] < -10913.264) {
            if (input[57] < -29083.434) {
                if (input[60] < -2237.9575) {
                    var43 = 0.045057606;
                } else {
                    var43 = -0.06857633;
                }
            } else {
                if (input[78] < -27261.818) {
                    var43 = -0.10678903;
                } else {
                    var43 = 0.037601914;
                }
            }
        } else {
            var43 = -0.09486054;
        }
    } else {
        if (input[46] < -2219.8452) {
            if (input[62] < -29974.574) {
                if (input[30] < -20672.389) {
                    var43 = -0.11400087;
                } else {
                    var43 = -0.015323654;
                }
            } else {
                if (input[89] < -20909.195) {
                    var43 = -0.08919675;
                } else {
                    var43 = 0.028194664;
                }
            }
        } else {
            if (input[29] < 5843.1104) {
                if (input[46] < 4894.4336) {
                    var43 = 0.042697635;
                } else {
                    var43 = -0.045474928;
                }
            } else {
                var43 = -0.111406915;
            }
        }
    }
    double var44;
    if (input[89] < -23831.863) {
        if (input[19] < -8854.306) {
            if (input[30] < -19934.5) {
                if (input[3] < -25031.25) {
                    var44 = -0.108363666;
                } else {
                    var44 = -0.02916801;
                }
            } else {
                var44 = 0.008860531;
            }
        } else {
            if (input[22] < -15869.87) {
                if (input[13] < 8277.85) {
                    var44 = -0.094990455;
                } else {
                    var44 = 0.019063618;
                }
            } else {
                if (input[19] < -4695.4434) {
                    var44 = 0.08451162;
                } else {
                    var44 = -0.066424355;
                }
            }
        }
    } else {
        if (input[77] < -26445.182) {
            if (input[89] < -23179.084) {
                var44 = 0.03471271;
            } else {
                if (input[48] < 3153.169) {
                    var44 = -0.108666316;
                } else {
                    var44 = -0.01181995;
                }
            }
        } else {
            if (input[56] < 9042.339) {
                if (input[93] < -20575.54) {
                    var44 = -0.10440878;
                } else {
                    var44 = 0.030093445;
                }
            } else {
                if (input[19] < -18712.852) {
                    var44 = -0.055024732;
                } else {
                    var44 = 0.031139975;
                }
            }
        }
    }
    double var45;
    if (input[87] < -20625.994) {
        if (input[50] < 2538.4124) {
            if (input[25] < -5340.4795) {
                if (input[20] < 4630.7026) {
                    var45 = -0.11065423;
                } else {
                    var45 = -0.02924852;
                }
            } else {
                if (input[2] < -22799.893) {
                    var45 = -0.08514228;
                } else {
                    var45 = 0.052740753;
                }
            }
        } else {
            if (input[46] < -4241.843) {
                if (input[87] < -21629.727) {
                    var45 = -0.09165476;
                } else {
                    var45 = -0.009507711;
                }
            } else {
                if (input[74] < -22295.168) {
                    var45 = 0.06585259;
                } else {
                    var45 = -0.04220369;
                }
            }
        }
    } else {
        if (input[41] < -15458.441) {
            if (input[60] < 136.92883) {
                if (input[95] < -5519.221) {
                    var45 = 0.08213927;
                } else {
                    var45 = -0.06470285;
                }
            } else {
                var45 = -0.100699745;
            }
        } else {
            if (input[13] < -12299.183) {
                var45 = -0.08671745;
            } else {
                if (input[63] < -25676.744) {
                    var45 = -0.057447255;
                } else {
                    var45 = 0.045861848;
                }
            }
        }
    }
    double var46;
    if (input[94] < 1340.8655) {
        if (input[45] < -29340.824) {
            if (input[3] < -25951.203) {
                var46 = -0.104905985;
            } else {
                var46 = -0.018782442;
            }
        } else {
            if (input[3] < -28503.95) {
                if (input[72] < -28334.18) {
                    var46 = -0.08317709;
                } else {
                    var46 = 0.022544991;
                }
            } else {
                if (input[77] < -25773.854) {
                    var46 = -0.043978002;
                } else {
                    var46 = 0.023322856;
                }
            }
        }
    } else {
        if (input[64] < -9772.404) {
            if (input[85] < 11133.9375) {
                var46 = -0.077837;
            } else {
                if (input[86] < 6937.189) {
                    var46 = -0.0054287165;
                } else {
                    var46 = 0.08781059;
                }
            }
        } else {
            if (input[85] < -27595.979) {
                var46 = 0.025692726;
            } else {
                var46 = -0.10828028;
            }
        }
    }
    double var47;
    if (input[4] < -28422.746) {
        if (input[76] < -18573.268) {
            if (input[40] < -26843.002) {
                var47 = 0.006627779;
            } else {
                var47 = 0.04674164;
            }
        } else {
            if (input[64] < -11479.374) {
                if (input[40] < -27233.547) {
                    var47 = -0.07254276;
                } else {
                    var47 = 0.07608046;
                }
            } else {
                var47 = -0.10283057;
            }
        }
    } else {
        if (input[10] < 26504.791) {
            if (input[9] < -29404.018) {
                if (input[24] < 6584.042) {
                    var47 = -0.07223086;
                } else {
                    var47 = 0.0224753;
                }
            } else {
                if (input[80] < -5836.1484) {
                    var47 = -0.017911157;
                } else {
                    var47 = 0.036990907;
                }
            }
        } else {
            if (input[74] < -26225.352) {
                var47 = -0.017675448;
            } else {
                var47 = -0.09383371;
            }
        }
    }
    double var48;
    if (input[93] < -24439.834) {
        if (input[34] < 7626.5825) {
            if (input[64] < -7638.6914) {
                if (input[76] < -7305.2944) {
                    var48 = -0.04986222;
                } else {
                    var48 = 0.07433498;
                }
            } else {
                if (input[7] < -28026.75) {
                    var48 = -0.09119172;
                } else {
                    var48 = 0.038925614;
                }
            }
        } else {
            if (input[27] < -28913.207) {
                if (input[70] < 26903.857) {
                    var48 = -0.10026168;
                } else {
                    var48 = 0.020466091;
                }
            } else {
                if (input[38] < -3078.2405) {
                    var48 = 0.058502134;
                } else {
                    var48 = -0.072738305;
                }
            }
        }
    } else {
        if (input[83] < -26220.473) {
            var48 = -0.09951889;
        } else {
            if (input[45] < -28848.33) {
                if (input[4] < -26080.627) {
                    var48 = -0.069564156;
                } else {
                    var48 = 0.023111155;
                }
            } else {
                if (input[29] < 5137.8735) {
                    var48 = 0.039325904;
                } else {
                    var48 = -0.04300579;
                }
            }
        }
    }
    double var49;
    if (input[1] < -26403.361) {
        if (input[87] < -14845.725) {
            if (input[71] < -26640.242) {
                var49 = -0.016158272;
            } else {
                var49 = -0.09866323;
            }
        } else {
            if (input[87] < -13013.622) {
                var49 = 0.059791952;
            } else {
                var49 = -0.059862174;
            }
        }
    } else {
        if (input[13] < 7939.9673) {
            if (input[36] < -28239.572) {
                if (input[95] < -1829.5404) {
                    var49 = -0.102813065;
                } else {
                    var49 = 0.01648497;
                }
            } else {
                if (input[31] < -840.6682) {
                    var49 = 0.014787269;
                } else {
                    var49 = -0.08503922;
                }
            }
        } else {
            if (input[81] < -11130.221) {
                if (input[37] < -12271.265) {
                    var49 = -0.011894901;
                } else {
                    var49 = 0.081963085;
                }
            } else {
                if (input[57] < -28707.29) {
                    var49 = -0.054609258;
                } else {
                    var49 = 0.05236235;
                }
            }
        }
    }
    double var50;
    if (input[6] < 3119.0164) {
        if (input[16] < -28418.137) {
            var50 = -0.103231885;
        } else {
            if (input[28] < -29968.105) {
                var50 = -0.07568549;
            } else {
                if (input[89] < -14599.619) {
                    var50 = 0.083261244;
                } else {
                    var50 = -0.039980706;
                }
            }
        }
    } else {
        if (input[63] < -25542.275) {
            if (input[6] < 23686.232) {
                if (input[64] < -23492.176) {
                    var50 = 0.045526456;
                } else {
                    var50 = -0.1077562;
                }
            } else {
                if (input[14] < 1379.3103) {
                    var50 = -0.04309371;
                } else {
                    var50 = 0.08868378;
                }
            }
        } else {
            if (input[82] < -3120.743) {
                if (input[59] < -12734.041) {
                    var50 = 0.033278305;
                } else {
                    var50 = -0.022135394;
                }
            } else {
                if (input[14] < 6475.0957) {
                    var50 = -0.07630026;
                } else {
                    var50 = 0.03981592;
                }
            }
        }
    }
    double var51;
    if (input[11] < -26216.514) {
        if (input[0] < -3203.946) {
            var51 = -0.09861263;
        } else {
            var51 = 0.02566737;
        }
    } else {
        if (input[41] < -3413.216) {
            if (input[41] < -15131.821) {
                if (input[81] < -10835.381) {
                    var51 = 0.0020562022;
                } else {
                    var51 = -0.104303256;
                }
            } else {
                if (input[91] < -29227.15) {
                    var51 = -0.023888536;
                } else {
                    var51 = 0.036188524;
                }
            }
        } else {
            if (input[55] < -25659.404) {
                if (input[43] < -12119.928) {
                    var51 = -0.11149726;
                } else {
                    var51 = 0.0047438606;
                }
            } else {
                var51 = 0.05641981;
            }
        }
    }
    double var52;
    if (input[87] < -20625.994) {
        if (input[92] < -11534.421) {
            if (input[13] < 7434.7725) {
                if (input[8] < -12515.591) {
                    var52 = -0.09994237;
                } else {
                    var52 = -0.01888524;
                }
            } else {
                if (input[20] < 2828.7568) {
                    var52 = -0.085346155;
                } else {
                    var52 = 0.04194872;
                }
            }
        } else {
            if (input[55] < -27988.797) {
                if (input[92] < -10868.169) {
                    var52 = 0.01813204;
                } else {
                    var52 = -0.10174596;
                }
            } else {
                if (input[52] < -13747.914) {
                    var52 = 0.069790475;
                } else {
                    var52 = -0.023297602;
                }
            }
        }
    } else {
        if (input[41] < -15458.441) {
            if (input[60] < 136.92883) {
                if (input[95] < -5519.221) {
                    var52 = 0.075029366;
                } else {
                    var52 = -0.058816202;
                }
            } else {
                var52 = -0.09460505;
            }
        } else {
            if (input[13] < -12299.183) {
                var52 = -0.08303406;
            } else {
                if (input[63] < -25676.744) {
                    var52 = -0.049780484;
                } else {
                    var52 = 0.041692406;
                }
            }
        }
    }
    double var53;
    if (input[73] < 3176.7595) {
        if (input[62] < -29973.94) {
            var53 = -0.099309176;
        } else {
            if (input[52] < -13599.705) {
                if (input[70] < 21979.783) {
                    var53 = 0.070346944;
                } else {
                    var53 = -0.0146379275;
                }
            } else {
                var53 = -0.07013057;
            }
        }
    } else {
        if (input[73] < 7173.4863) {
            if (input[75] < -29921.525) {
                if (input[58] < -20877.307) {
                    var53 = 0.07229443;
                } else {
                    var53 = -0.006482774;
                }
            } else {
                var53 = -0.09436517;
            }
        } else {
            if (input[2] < -19908.18) {
                if (input[44] < 8690.61) {
                    var53 = -0.059236865;
                } else {
                    var53 = 0.02530849;
                }
            } else {
                if (input[87] < -20625.994) {
                    var53 = -0.035180286;
                } else {
                    var53 = 0.037875578;
                }
            }
        }
    }
    double var54;
    if (input[93] < -24460.432) {
        if (input[34] < 7626.5825) {
            if (input[45] < -27420.75) {
                if (input[64] < -7638.6914) {
                    var54 = 0.057132073;
                } else {
                    var54 = -0.03230759;
                }
            } else {
                var54 = -0.08553389;
            }
        } else {
            if (input[27] < -29313.531) {
                if (input[85] < 19011.883) {
                    var54 = -0.10806006;
                } else {
                    var54 = -0.019946536;
                }
            } else {
                if (input[57] < -28874.91) {
                    var54 = -0.08660818;
                } else {
                    var54 = 0.038016107;
                }
            }
        }
    } else {
        if (input[83] < -26220.473) {
            var54 = -0.093950756;
        } else {
            if (input[76] < -5501.2344) {
                if (input[94] < 2098.2563) {
                    var54 = 0.04212565;
                } else {
                    var54 = -0.09258806;
                }
            } else {
                if (input[32] < -29627.062) {
                    var54 = -0.053028494;
                } else {
                    var54 = 0.036615487;
                }
            }
        }
    }
    double var55;
    if (input[26] < -22309.15) {
        if (input[46] < -7005.7583) {
            if (input[78] < -22314.635) {
                if (input[64] < -5953.058) {
                    var55 = 0.05345581;
                } else {
                    var55 = -0.044957336;
                }
            } else {
                if (input[50] < -5462.871) {
                    var55 = -0.0029907431;
                } else {
                    var55 = -0.10196477;
                }
            }
        } else {
            if (input[29] < -1396.4152) {
                if (input[27] < -28941.861) {
                    var55 = -0.042880233;
                } else {
                    var55 = 0.04546641;
                }
            } else {
                if (input[89] < -23942.715) {
                    var55 = -0.031068617;
                } else {
                    var55 = 0.051137906;
                }
            }
        }
    } else {
        if (input[97] < -4548.1616) {
            if (input[55] < -27630.393) {
                if (input[4] < -20731.865) {
                    var55 = -0.09310145;
                } else {
                    var55 = 0.033830743;
                }
            } else {
                if (input[22] < -16662.004) {
                    var55 = -0.04238829;
                } else {
                    var55 = 0.06455921;
                }
            }
        } else {
            if (input[14] < -805.7484) {
                var55 = -0.011396605;
            } else {
                if (input[47] < -17381.61) {
                    var55 = -0.116674714;
                } else {
                    var55 = -0.029270513;
                }
            }
        }
    }
    double var56;
    if (input[6] < 3119.0164) {
        if (input[16] < -28418.137) {
            var56 = -0.09969872;
        } else {
            if (input[28] < -29968.105) {
                var56 = -0.06900655;
            } else {
                if (input[89] < -17754.258) {
                    var56 = 0.07734389;
                } else {
                    var56 = -0.027844122;
                }
            }
        }
    } else {
        if (input[88] < 15513.345) {
            if (input[41] < -15364.108) {
                if (input[85] < -22271.531) {
                    var56 = 0.055111792;
                } else {
                    var56 = -0.07865335;
                }
            } else {
                if (input[56] < 8958.503) {
                    var56 = -0.057290103;
                } else {
                    var56 = 0.03738458;
                }
            }
        } else {
            if (input[17] < -1491.4425) {
                if (input[44] < -26098.592) {
                    var56 = 0.048303477;
                } else {
                    var56 = -0.05417868;
                }
            } else {
                if (input[87] < -22490.22) {
                    var56 = -0.0764737;
                } else {
                    var56 = 0.07797913;
                }
            }
        }
    }
    double var57;
    if (input[15] < -20909.092) {
        if (input[27] < -29391.072) {
            if (input[37] < -11523.8) {
                if (input[87] < -23368.617) {
                    var57 = -0.09469349;
                } else {
                    var57 = 0.035763074;
                }
            } else {
                var57 = -0.10326793;
            }
        } else {
            if (input[45] < -29200.814) {
                var57 = -0.09201326;
            } else {
                if (input[59] < -13279.018) {
                    var57 = 0.045685362;
                } else {
                    var57 = -0.010768416;
                }
            }
        }
    } else {
        if (input[27] < -29348.854) {
            if (input[29] < 971.23804) {
                if (input[9] < -28552.117) {
                    var57 = -0.07911955;
                } else {
                    var57 = 0.07433761;
                }
            } else {
                if (input[72] < -28679.555) {
                    var57 = 0.09554451;
                } else {
                    var57 = -0.046788607;
                }
            }
        } else {
            if (input[9] < -28687.678) {
                if (input[9] < -28789.73) {
                    var57 = -0.10419978;
                } else {
                    var57 = -0.03336912;
                }
            } else {
                if (input[87] < -20534.55) {
                    var57 = -0.06133029;
                } else {
                    var57 = 0.04275733;
                }
            }
        }
    }
    double var58;
    if (input[1] < -26403.361) {
        if (input[87] < -14845.725) {
            if (input[67] < -25526.201) {
                var58 = -0.023001838;
            } else {
                var58 = -0.09312843;
            }
        } else {
            if (input[26] < -24796.818) {
                var58 = 0.04971024;
            } else {
                var58 = -0.054651808;
            }
        }
    } else {
        if (input[41] < -3413.216) {
            if (input[81] < -10098.28) {
                if (input[55] < -28095.553) {
                    var58 = -0.02661472;
                } else {
                    var58 = 0.038843866;
                }
            } else {
                if (input[77] < -16121.988) {
                    var58 = -0.03942462;
                } else {
                    var58 = 0.06450789;
                }
            }
        } else {
            if (input[57] < -27689.867) {
                if (input[99] < -25402.125) {
                    var58 = 0.004974292;
                } else {
                    var58 = -0.096746325;
                }
            } else {
                var58 = 0.050514795;
            }
        }
    }
    double var59;
    if (input[69] < -751.58466) {
        if (input[30] < -27854.078) {
            if (input[77] < -18755.139) {
                if (input[87] < -15257.741) {
                    var59 = -0.10638205;
                } else {
                    var59 = 0.002229854;
                }
            } else {
                if (input[82] < -13074.851) {
                    var59 = -0.049327385;
                } else {
                    var59 = 0.0715525;
                }
            }
        } else {
            if (input[81] < -10098.28) {
                if (input[65] < -12586.535) {
                    var59 = -0.091110535;
                } else {
                    var59 = 0.03760922;
                }
            } else {
                if (input[78] < -19607.22) {
                    var59 = 0.003361306;
                } else {
                    var59 = -0.07599739;
                }
            }
        }
    } else {
        if (input[43] < -6842.2104) {
            if (input[70] < -22379.379) {
                var59 = 0.009345055;
            } else {
                var59 = -0.09653351;
            }
        } else {
            if (input[38] < -9532.304) {
                var59 = 0.06945508;
            } else {
                var59 = -0.04555485;
            }
        }
    }
    double var60;
    if (input[93] < -24415.834) {
        if (input[91] < -29224.684) {
            if (input[65] < 5473.2065) {
                var60 = -0.10477334;
            } else {
                var60 = -0.013789654;
            }
        } else {
            if (input[49] < -26851.973) {
                var60 = -0.08895391;
            } else {
                if (input[73] < 11830.605) {
                    var60 = 0.02489316;
                } else {
                    var60 = -0.059919633;
                }
            }
        }
    } else {
        if (input[45] < -28961.295) {
            if (input[29] < 1708.0819) {
                if (input[27] < -28374.67) {
                    var60 = -0.09740733;
                } else {
                    var60 = 0.0067715794;
                }
            } else {
                if (input[89] < -18013.312) {
                    var60 = -0.034767408;
                } else {
                    var60 = 0.06602815;
                }
            }
        } else {
            if (input[20] < -19405.297) {
                if (input[97] < -6032.483) {
                    var60 = -0.028056998;
                } else {
                    var60 = -0.10999612;
                }
            } else {
                if (input[83] < -24566.93) {
                    var60 = -0.04801826;
                } else {
                    var60 = 0.031636246;
                }
            }
        }
    }
    double var61;
    if (input[4] < -28626.29) {
        if (input[8] < -15205.246) {
            var61 = -0.08736639;
        } else {
            var61 = 0.00334013;
        }
    } else {
        if (input[10] < 26730.783) {
            if (input[67] < -22639.28) {
                if (input[70] < -13447.498) {
                    var61 = -0.054694284;
                } else {
                    var61 = 0.03720575;
                }
            } else {
                if (input[32] < -29706.047) {
                    var61 = -0.035816252;
                } else {
                    var61 = 0.025511054;
                }
            }
        } else {
            var61 = -0.08581837;
        }
    }
    double var62;
    if (input[6] < 3119.0164) {
        if (input[7] < -28138.033) {
            if (input[16] < -28418.137) {
                var62 = -0.09612955;
            } else {
                var62 = -0.02270315;
            }
        } else {
            if (input[66] < -27591.426) {
                var62 = 0.0593714;
            } else {
                var62 = -0.034956526;
            }
        }
    } else {
        if (input[64] < -8332.473) {
            if (input[39] < -26541.928) {
                if (input[38] < -9532.304) {
                    var62 = 0.019379292;
                } else {
                    var62 = -0.07890055;
                }
            } else {
                if (input[81] < -14682.176) {
                    var62 = -0.047558922;
                } else {
                    var62 = 0.05516025;
                }
            }
        } else {
            if (input[7] < -29208.812) {
                if (input[28] < -29927.738) {
                    var62 = -0.08934166;
                } else {
                    var62 = 0.061504226;
                }
            } else {
                if (input[24] < 10327.869) {
                    var62 = 0.01810409;
                } else {
                    var62 = -0.062293716;
                }
            }
        }
    }
    double var63;
    if (input[1] < -26403.361) {
        if (input[87] < -14845.725) {
            if (input[58] < -25665.008) {
                var63 = -0.022850415;
            } else {
                var63 = -0.09046586;
            }
        } else {
            if (input[26] < -25039.475) {
                var63 = 0.04243583;
            } else {
                var63 = -0.037504606;
            }
        }
    } else {
        if (input[83] < -26929.135) {
            var63 = -0.0882546;
        } else {
            if (input[69] < -21.128885) {
                if (input[94] < 1673.1559) {
                    var63 = 0.017123355;
                } else {
                    var63 = -0.050006807;
                }
            } else {
                if (input[43] < -7496.926) {
                    var63 = -0.08823457;
                } else {
                    var63 = 0.018488035;
                }
            }
        }
    }
    double var64;
    if (input[73] < 3176.7595) {
        if (input[97] < -27114.293) {
            if (input[35] < 6907.5493) {
                var64 = -0.034124672;
            } else {
                var64 = 0.04842153;
            }
        } else {
            if (input[56] < 7982.099) {
                var64 = -0.012312687;
            } else {
                var64 = -0.09464091;
            }
        }
    } else {
        if (input[73] < 7173.4863) {
            if (input[75] < -29921.525) {
                if (input[94] < -4805.5903) {
                    var64 = 0.057992198;
                } else {
                    var64 = -0.027383093;
                }
            } else {
                var64 = -0.087044716;
            }
        } else {
            if (input[55] < -27607.652) {
                if (input[0] < -2331.481) {
                    var64 = -0.07040881;
                } else {
                    var64 = -0.0036658074;
                }
            } else {
                if (input[82] < -3120.743) {
                    var64 = 0.024520611;
                } else {
                    var64 = -0.08220037;
                }
            }
        }
    }
    double var65;
    if (input[93] < -24415.834) {
        if (input[63] < 848.3366) {
            if (input[38] < 4475.706) {
                if (input[74] < -23425.352) {
                    var65 = -0.032088052;
                } else {
                    var65 = -0.09976604;
                }
            } else {
                if (input[50] < 737.9488) {
                    var65 = -0.05770647;
                } else {
                    var65 = 0.066373;
                }
            }
        } else {
            if (input[60] < 660.6071) {
                if (input[82] < -8029.102) {
                    var65 = 0.08513268;
                } else {
                    var65 = -0.003529692;
                }
            } else {
                if (input[17] < -10590.396) {
                    var65 = 0.005921018;
                } else {
                    var65 = -0.08019182;
                }
            }
        }
    } else {
        if (input[22] < -16474.205) {
            if (input[87] < -22047.746) {
                if (input[85] < -26096.541) {
                    var65 = 0.024672141;
                } else {
                    var65 = -0.080918126;
                }
            } else {
                if (input[26] < -22309.15) {
                    var65 = 0.03195675;
                } else {
                    var65 = -0.055868722;
                }
            }
        } else {
            if (input[93] < 11174.595) {
                if (input[14] < -5210.728) {
                    var65 = -0.04722248;
                } else {
                    var65 = 0.046951618;
                }
            } else {
                if (input[71] < -22136.953) {
                    var65 = -0.10775266;
                } else {
                    var65 = 0.0432393;
                }
            }
        }
    }
    double var66;
    if (input[35] < -2652.843) {
        if (input[77] < -17902.049) {
            if (input[95] < 491.80328) {
                if (input[41] < -3898.1055) {
                    var66 = -0.096496806;
                } else {
                    var66 = -0.02543723;
                }
            } else {
                if (input[63] < -21792.402) {
                    var66 = 0.055519637;
                } else {
                    var66 = -0.05710849;
                }
            }
        } else {
            if (input[57] < -28771.969) {
                if (input[10] < 94.06607) {
                    var66 = -0.06389872;
                } else {
                    var66 = 0.00059644977;
                }
            } else {
                if (input[63] < -18902.145) {
                    var66 = -0.024032773;
                } else {
                    var66 = 0.07762628;
                }
            }
        }
    } else {
        if (input[43] < -23785.584) {
            if (input[34] < 4551.1284) {
                var66 = 0.012016266;
            } else {
                var66 = -0.089840315;
            }
        } else {
            if (input[91] < -29283.88) {
                if (input[67] < -22065.28) {
                    var66 = 0.002551394;
                } else {
                    var66 = -0.08406336;
                }
            } else {
                if (input[55] < -28654.81) {
                    var66 = -0.0643036;
                } else {
                    var66 = 0.026509687;
                }
            }
        }
    }
    double var67;
    if (input[46] < -3742.8022) {
        if (input[78] < -19791.816) {
            if (input[42] < -23412.496) {
                if (input[98] < -10090.391) {
                    var67 = 0.03984054;
                } else {
                    var67 = -0.029678935;
                }
            } else {
                if (input[50] < -1535.4097) {
                    var67 = -0.016319398;
                } else {
                    var67 = -0.08976745;
                }
            }
        } else {
            if (input[50] < -5094.2275) {
                var67 = 0.01868665;
            } else {
                var67 = -0.09231975;
            }
        }
    } else {
        if (input[50] < 2020.8254) {
            if (input[75] < -29955.8) {
                if (input[64] < 11031.295) {
                    var67 = -0.091435224;
                } else {
                    var67 = 0.01826741;
                }
            } else {
                if (input[45] < -28323.498) {
                    var67 = -0.045623753;
                } else {
                    var67 = 0.033482075;
                }
            }
        } else {
            if (input[99] < -18869.5) {
                if (input[77] < -26092.162) {
                    var67 = -0.06593301;
                } else {
                    var67 = 0.055651348;
                }
            } else {
                if (input[1] < -23664.25) {
                    var67 = -0.08308225;
                } else {
                    var67 = 0.030892132;
                }
            }
        }
    }
    double var68;
    if (input[15] < -20909.092) {
        if (input[27] < -29391.072) {
            if (input[37] < -11523.8) {
                if (input[87] < -23368.617) {
                    var68 = -0.08372497;
                } else {
                    var68 = 0.029639969;
                }
            } else {
                var68 = -0.095645264;
            }
        } else {
            if (input[45] < -29200.814) {
                var68 = -0.08386063;
            } else {
                if (input[84] < -28556.387) {
                    var68 = 0.03196186;
                } else {
                    var68 = -0.060141664;
                }
            }
        }
    } else {
        if (input[27] < -29348.854) {
            if (input[29] < 971.23804) {
                if (input[9] < -28552.117) {
                    var68 = -0.07331534;
                } else {
                    var68 = 0.06166607;
                }
            } else {
                if (input[72] < -28768.7) {
                    var68 = 0.08663356;
                } else {
                    var68 = -0.01927766;
                }
            }
        } else {
            if (input[9] < -28687.678) {
                if (input[9] < -28789.73) {
                    var68 = -0.09905837;
                } else {
                    var68 = -0.029854808;
                }
            } else {
                if (input[8] < -16894.889) {
                    var68 = -0.046003684;
                } else {
                    var68 = 0.049961265;
                }
            }
        }
    }
    double var69;
    if (input[59] < -13279.018) {
        if (input[38] < -5287.958) {
            if (input[89] < -25126.156) {
                if (input[44] < -14304.292) {
                    var69 = -0.0031832343;
                } else {
                    var69 = -0.078461096;
                }
            } else {
                if (input[12] < -1270.903) {
                    var69 = 0.05168373;
                } else {
                    var69 = -0.043609083;
                }
            }
        } else {
            if (input[64] < -6558.6006) {
                if (input[83] < -24566.93) {
                    var69 = -0.058908522;
                } else {
                    var69 = 0.040843546;
                }
            } else {
                if (input[56] < 17601.63) {
                    var69 = -0.062576406;
                } else {
                    var69 = 0.02102731;
                }
            }
        }
    } else {
        if (input[42] < -24674.53) {
            if (input[1] < -25975.887) {
                var69 = -0.080696926;
            } else {
                if (input[78] < -18794.996) {
                    var69 = 0.046197776;
                } else {
                    var69 = -0.061553217;
                }
            }
        } else {
            if (input[10] < 1977.7778) {
                if (input[61] < 14826.701) {
                    var69 = 0.021033004;
                } else {
                    var69 = -0.100245774;
                }
            } else {
                if (input[75] < -29950.594) {
                    var69 = -0.055913556;
                } else {
                    var69 = 0.047638755;
                }
            }
        }
    }
    double var70;
    if (input[73] < 3176.7595) {
        if (input[62] < -29973.94) {
            var70 = -0.08989334;
        } else {
            if (input[87] < -20769.23) {
                var70 = -0.04900702;
            } else {
                var70 = 0.036364187;
            }
        }
    } else {
        if (input[55] < -28256.16) {
            if (input[63] < 848.3366) {
                if (input[59] < -16869.53) {
                    var70 = 0.015046108;
                } else {
                    var70 = -0.09382698;
                }
            } else {
                if (input[13] < 5452.721) {
                    var70 = -0.044234835;
                } else {
                    var70 = 0.06254767;
                }
            }
        } else {
            if (input[46] < -3742.8022) {
                if (input[97] < -20787.426) {
                    var70 = 0.027899602;
                } else {
                    var70 = -0.051463168;
                }
            } else {
                if (input[54] < -26765.607) {
                    var70 = -0.018195618;
                } else {
                    var70 = 0.04099829;
                }
            }
        }
    }
    double var71;
    if (input[3] < -28537.5) {
        if (input[72] < -28314.828) {
            if (input[99] < -18220.79) {
                var71 = -0.08937968;
            } else {
                var71 = -0.011815108;
            }
        } else {
            if (input[64] < -12225.659) {
                var71 = 0.05310454;
            } else {
                var71 = -0.027945815;
            }
        }
    } else {
        if (input[67] < -22639.28) {
            if (input[82] < -3120.743) {
                if (input[81] < -15151.466) {
                    var71 = -0.06365032;
                } else {
                    var71 = 0.03964076;
                }
            } else {
                if (input[76] < 840.03485) {
                    var71 = -0.08281501;
                } else {
                    var71 = 0.020370392;
                }
            }
        } else {
            if (input[91] < -29273.607) {
                if (input[93] < -19841.727) {
                    var71 = -0.09369956;
                } else {
                    var71 = -0.005420159;
                }
            } else {
                if (input[76] < -5786.2583) {
                    var71 = 0.025077645;
                } else {
                    var71 = -0.042983208;
                }
            }
        }
    }
    double var72;
    if (input[4] < -28422.746) {
        if (input[85] < -25097.373) {
            var72 = 0.023338472;
        } else {
            if (input[24] < 16922.973) {
                var72 = -0.090230264;
            } else {
                var72 = -0.0011847237;
            }
        }
    } else {
        if (input[4] < -28101.55) {
            if (input[46] < -2219.8452) {
                if (input[34] < 6945.4604) {
                    var72 = 0.023382911;
                } else {
                    var72 = -0.060489755;
                }
            } else {
                if (input[33] < -29171.354) {
                    var72 = -0.0014060765;
                } else {
                    var72 = 0.08834884;
                }
            }
        } else {
            if (input[83] < -22138.326) {
                if (input[78] < -23213.004) {
                    var72 = 0.0036313948;
                } else {
                    var72 = -0.068080306;
                }
            } else {
                if (input[0] < -2331.481) {
                    var72 = -0.01847844;
                } else {
                    var72 = 0.033131305;
                }
            }
        }
    }
    double var73;
    if (input[10] < 26730.783) {
        if (input[93] < -24415.834) {
            if (input[64] < -794.46967) {
                if (input[76] < -7079.4097) {
                    var73 = -0.05565585;
                } else {
                    var73 = 0.03266206;
                }
            } else {
                if (input[52] < -18784.78) {
                    var73 = 0.0064924173;
                } else {
                    var73 = -0.0743129;
                }
            }
        } else {
            if (input[80] < -10954.284) {
                if (input[34] < 13710.994) {
                    var73 = -0.06936552;
                } else {
                    var73 = 0.035601716;
                }
            } else {
                if (input[86] < -900.57556) {
                    var73 = -0.053889897;
                } else {
                    var73 = 0.031139687;
                }
            }
        }
    } else {
        var73 = -0.080482;
    }
    double var74;
    if (input[59] < -13308.458) {
        if (input[21] < -10913.264) {
            if (input[57] < -29083.434) {
                if (input[60] < -2481.486) {
                    var74 = 0.03599077;
                } else {
                    var74 = -0.05312403;
                }
            } else {
                if (input[13] < -12299.183) {
                    var74 = -0.05861749;
                } else {
                    var74 = 0.03238116;
                }
            }
        } else {
            var74 = -0.076591566;
        }
    } else {
        if (input[29] < 5843.1104) {
            if (input[46] < -3427.8955) {
                if (input[60] < 5589.4243) {
                    var74 = -0.08658476;
                } else {
                    var74 = -0.002904409;
                }
            } else {
                if (input[60] < 8264.5) {
                    var74 = 0.026044583;
                } else {
                    var74 = -0.0565342;
                }
            }
        } else {
            var74 = -0.09492203;
        }
    }
    double var75;
    if (input[1] < -26403.361) {
        if (input[88] < 12589.134) {
            var75 = 0.004007963;
        } else {
            var75 = -0.07885774;
        }
    } else {
        if (input[4] < -28422.746) {
            if (input[85] < -25097.373) {
                var75 = 0.023623718;
            } else {
                if (input[19] < -5952.4077) {
                    var75 = -0.09157718;
                } else {
                    var75 = -0.012995918;
                }
            }
        } else {
            if (input[42] < -22062.633) {
                if (input[94] < 1340.8655) {
                    var75 = 0.018326577;
                } else {
                    var75 = -0.04870774;
                }
            } else {
                if (input[85] < -11868.731) {
                    var75 = 0.020679845;
                } else {
                    var75 = -0.08109041;
                }
            }
        }
    }
    double var76;
    if (input[73] < 2315.0574) {
        if (input[12] < -13598.595) {
            var76 = 0.005460274;
        } else {
            var76 = -0.08330455;
        }
    } else {
        if (input[73] < 7193.126) {
            if (input[75] < -29921.525) {
                if (input[24] < -4023.8218) {
                    var76 = -0.049882963;
                } else {
                    var76 = 0.048433162;
                }
            } else {
                var76 = -0.07741424;
            }
        } else {
            if (input[87] < -20625.994) {
                if (input[43] < -8776.499) {
                    var76 = -0.063462935;
                } else {
                    var76 = 0.02634557;
                }
            } else {
                if (input[75] < -29955.8) {
                    var76 = -0.054659415;
                } else {
                    var76 = 0.031568624;
                }
            }
        }
    }
    double var77;
    if (input[55] < -27846.297) {
        if (input[26] < -21916.07) {
            if (input[87] < -21947.98) {
                if (input[70] < 25019.248) {
                    var77 = -0.07967751;
                } else {
                    var77 = 0.01553815;
                }
            } else {
                if (input[66] < -27957.125) {
                    var77 = -0.06365356;
                } else {
                    var77 = 0.03335617;
                }
            }
        } else {
            if (input[8] < -14459.356) {
                var77 = -0.09579061;
            } else {
                var77 = -0.007900281;
            }
        }
    } else {
        if (input[46] < -9001.919) {
            if (input[97] < -16473.45) {
                if (input[87] < -18552.5) {
                    var77 = -0.039415922;
                } else {
                    var77 = 0.06643156;
                }
            } else {
                var77 = -0.08707368;
            }
        } else {
            if (input[27] < -29344.227) {
                if (input[34] < 7822.723) {
                    var77 = 0.024976438;
                } else {
                    var77 = -0.04533344;
                }
            } else {
                if (input[37] < -13467.852) {
                    var77 = -0.054356612;
                } else {
                    var77 = 0.06076327;
                }
            }
        }
    }
    double var78;
    if (input[6] < 3119.0164) {
        if (input[7] < -28138.033) {
            var78 = -0.08331264;
        } else {
            if (input[88] < 15438.346) {
                var78 = -0.033589218;
            } else {
                var78 = 0.05096374;
            }
        }
    } else {
        if (input[63] < -25542.275) {
            if (input[6] < 23686.232) {
                if (input[24] < 20406.3) {
                    var78 = -0.09533313;
                } else {
                    var78 = 0.032609783;
                }
            } else {
                var78 = 0.030923938;
            }
        } else {
            if (input[89] < -26121.492) {
                if (input[86] < 2323.1858) {
                    var78 = 0.019220255;
                } else {
                    var78 = -0.090971485;
                }
            } else {
                if (input[43] < -24185.342) {
                    var78 = -0.07009684;
                } else {
                    var78 = 0.017985195;
                }
            }
        }
    }
    double var79;
    if (input[41] < -3413.216) {
        if (input[41] < -14669.012) {
            if (input[85] < -22271.531) {
                if (input[81] < -10956.165) {
                    var79 = 0.06100133;
                } else {
                    var79 = -0.034548394;
                }
            } else {
                if (input[63] < -1584.7097) {
                    var79 = -0.082890205;
                } else {
                    var79 = 0.014961175;
                }
            }
        } else {
            if (input[94] < 1340.8655) {
                if (input[77] < -20797.848) {
                    var79 = -0.0011423121;
                } else {
                    var79 = 0.04705167;
                }
            } else {
                if (input[35] < 11669.951) {
                    var79 = -0.08055779;
                } else {
                    var79 = 0.0008054214;
                }
            }
        }
    } else {
        if (input[57] < -27747.535) {
            if (input[99] < -25402.125) {
                var79 = 0.0076954076;
            } else {
                if (input[34] < 4313.49) {
                    var79 = -0.026684513;
                } else {
                    var79 = -0.0942031;
                }
            }
        } else {
            var79 = 0.036904648;
        }
    }
    double var80;
    if (input[15] < -20909.092) {
        if (input[27] < -29391.072) {
            if (input[56] < 14817.706) {
                var80 = -0.08574862;
            } else {
                if (input[37] < -11523.8) {
                    var80 = 0.03116254;
                } else {
                    var80 = -0.07199007;
                }
            }
        } else {
            if (input[59] < -13279.018) {
                if (input[13] < -12299.183) {
                    var80 = -0.05233572;
                } else {
                    var80 = 0.041179273;
                }
            } else {
                if (input[43] < -7496.926) {
                    var80 = -0.03731824;
                } else {
                    var80 = 0.05321723;
                }
            }
        }
    } else {
        if (input[27] < -29348.854) {
            if (input[29] < 971.23804) {
                if (input[9] < -28552.117) {
                    var80 = -0.06489383;
                } else {
                    var80 = 0.052897006;
                }
            } else {
                if (input[29] < 5298.041) {
                    var80 = 0.08320751;
                } else {
                    var80 = -0.013123821;
                }
            }
        } else {
            if (input[9] < -28687.678) {
                var80 = -0.091321394;
            } else {
                if (input[87] < -20534.55) {
                    var80 = -0.04972739;
                } else {
                    var80 = 0.037670024;
                }
            }
        }
    }
    double var81;
    if (input[3] < -28537.5) {
        if (input[33] < -6988.204) {
            var81 = -0.07687151;
        } else {
            if (input[77] < -19316.014) {
                var81 = -0.03480696;
            } else {
                var81 = 0.049221974;
            }
        }
    } else {
        if (input[22] < -16322.156) {
            if (input[87] < -23280.115) {
                if (input[92] < -9197.601) {
                    var81 = -0.085647814;
                } else {
                    var81 = -0.0038472705;
                }
            } else {
                if (input[97] < -17905.355) {
                    var81 = 0.04223029;
                } else {
                    var81 = -0.025666565;
                }
            }
        } else {
            if (input[20] < -16666.703) {
                if (input[96] < -661.5087) {
                    var81 = 0.028225953;
                } else {
                    var81 = -0.080260605;
                }
            } else {
                if (input[81] < -9950.86) {
                    var81 = 0.04032571;
                } else {
                    var81 = -0.011087802;
                }
            }
        }
    }
    double var82;
    if (input[35] < -2652.843) {
        if (input[77] < -17902.049) {
            if (input[95] < 491.80328) {
                if (input[11] < -18947.55) {
                    var82 = -0.09062915;
                } else {
                    var82 = -0.027256703;
                }
            } else {
                if (input[82] < -5997.067) {
                    var82 = -0.03788873;
                } else {
                    var82 = 0.04589928;
                }
            }
        } else {
            if (input[44] < 6656.484) {
                if (input[85] < 13951.5) {
                    var82 = -0.060177416;
                } else {
                    var82 = 0.029556805;
                }
            } else {
                var82 = 0.06192839;
            }
        }
    } else {
        if (input[55] < -27826.59) {
            if (input[35] < 4925.373) {
                if (input[83] < -23020.2) {
                    var82 = -0.059696544;
                } else {
                    var82 = 0.039763868;
                }
            } else {
                if (input[74] < -26433.803) {
                    var82 = 0.04089935;
                } else {
                    var82 = -0.07947259;
                }
            }
        } else {
            if (input[46] < -9001.919) {
                if (input[57] < -28361.727) {
                    var82 = -0.08145843;
                } else {
                    var82 = 0.024487196;
                }
            } else {
                if (input[33] < -24366.525) {
                    var82 = -0.014320117;
                } else {
                    var82 = 0.046490263;
                }
            }
        }
    }
    double var83;
    if (input[32] < -29706.047) {
        if (input[67] < -22639.28) {
            if (input[20] < -5928.0) {
                if (input[67] < -23719.752) {
                    var83 = -0.07707673;
                } else {
                    var83 = 0.014280066;
                }
            } else {
                if (input[8] < -20691.154) {
                    var83 = -0.054814856;
                } else {
                    var83 = 0.042683735;
                }
            }
        } else {
            if (input[45] < -28370.775) {
                if (input[69] < -1729.5503) {
                    var83 = -0.0953847;
                } else {
                    var83 = -0.0035069324;
                }
            } else {
                if (input[51] < -13838.927) {
                    var83 = -0.07676198;
                } else {
                    var83 = 0.0084718885;
                }
            }
        }
    } else {
        if (input[14] < -2796.9348) {
            if (input[6] < 11366.062) {
                if (input[83] < -21697.635) {
                    var83 = -0.041256394;
                } else {
                    var83 = 0.05248316;
                }
            } else {
                var83 = -0.085894145;
            }
        } else {
            if (input[73] < 11234.043) {
                if (input[39] < -25961.51) {
                    var83 = -0.006109995;
                } else {
                    var83 = 0.06568149;
                }
            } else {
                if (input[69] < -9082.402) {
                    var83 = -0.057229888;
                } else {
                    var83 = 0.028956717;
                }
            }
        }
    }
    double var84;
    if (input[93] < -24460.432) {
        if (input[59] < -15508.011) {
            if (input[64] < -341.394) {
                if (input[96] < -4.359834) {
                    var84 = -0.05981024;
                } else {
                    var84 = 0.051238067;
                }
            } else {
                if (input[73] < 6112.9297) {
                    var84 = -0.00096550974;
                } else {
                    var84 = -0.07739228;
                }
            }
        } else {
            if (input[43] < -10157.48) {
                if (input[27] < -28685.848) {
                    var84 = -0.08429323;
                } else {
                    var84 = 0.00018853106;
                }
            } else {
                if (input[94] < -12797.543) {
                    var84 = 0.03426421;
                } else {
                    var84 = -0.048045788;
                }
            }
        }
    } else {
        if (input[21] < -12904.82) {
            if (input[83] < -24566.93) {
                if (input[14] < 2730.6387) {
                    var84 = -0.07257148;
                } else {
                    var84 = -0.0016724898;
                }
            } else {
                if (input[20] < -19405.297) {
                    var84 = -0.073546976;
                } else {
                    var84 = 0.028991396;
                }
            }
        } else {
            if (input[36] < -27363.953) {
                var84 = -0.08228214;
            } else {
                if (input[33] < -17777.258) {
                    var84 = -0.0017588375;
                } else {
                    var84 = 0.06221175;
                }
            }
        }
    }
    double var85;
    if (input[26] < -22309.15) {
        if (input[41] < -14718.473) {
            if (input[89] < -17288.562) {
                if (input[63] < -1584.7097) {
                    var85 = -0.08588271;
                } else {
                    var85 = -0.008403492;
                }
            } else {
                if (input[10] < 1050.2958) {
                    var85 = -0.041678328;
                } else {
                    var85 = 0.067067295;
                }
            }
        } else {
            if (input[94] < -1690.1376) {
                if (input[22] < -15472.536) {
                    var85 = -0.0009499231;
                } else {
                    var85 = 0.049945205;
                }
            } else {
                if (input[57] < -28882.754) {
                    var85 = 0.0075590196;
                } else {
                    var85 = -0.082242295;
                }
            }
        }
    } else {
        if (input[97] < -4548.1616) {
            if (input[55] < -27630.393) {
                if (input[4] < -20731.865) {
                    var85 = -0.07535825;
                } else {
                    var85 = 0.023761235;
                }
            } else {
                if (input[87] < -20769.23) {
                    var85 = -0.024573287;
                } else {
                    var85 = 0.057965647;
                }
            }
        } else {
            if (input[85] < -4826.4033) {
                var85 = -0.02963118;
            } else {
                var85 = -0.095464;
            }
        }
    }
    double var86;
    if (input[1] < -26403.361) {
        if (input[88] < 12589.134) {
            var86 = 0.006045016;
        } else {
            var86 = -0.07390216;
        }
    } else {
        if (input[13] < 7939.9673) {
            if (input[45] < -28929.9) {
                if (input[17] < -15150.492) {
                    var86 = -0.00053207006;
                } else {
                    var86 = -0.080818735;
                }
            } else {
                if (input[89] < -23831.863) {
                    var86 = -0.040713634;
                } else {
                    var86 = 0.011392311;
                }
            }
        } else {
            if (input[21] < -21010.889) {
                if (input[13] < 11613.259) {
                    var86 = 0.010753782;
                } else {
                    var86 = -0.068277985;
                }
            } else {
                if (input[56] < 13358.886) {
                    var86 = -0.0202012;
                } else {
                    var86 = 0.053467013;
                }
            }
        }
    }
    double var87;
    if (input[2] < -19857.143) {
        if (input[15] < -22159.092) {
            if (input[45] < -27369.945) {
                if (input[29] < -1322.4153) {
                    var87 = -0.035005577;
                } else {
                    var87 = 0.03880638;
                }
            } else {
                if (input[11] < -19697.87) {
                    var87 = -0.08042062;
                } else {
                    var87 = -0.00034558796;
                }
            }
        } else {
            if (input[27] < -29348.854) {
                if (input[70] < 24742.934) {
                    var87 = -0.039653588;
                } else {
                    var87 = 0.052934565;
                }
            } else {
                if (input[25] < -1247.1077) {
                    var87 = -0.09189277;
                } else {
                    var87 = -0.0072694244;
                }
            }
        }
    } else {
        if (input[37] < -13460.073) {
            var87 = -0.081368424;
        } else {
            if (input[76] < -5397.2876) {
                if (input[47] < -26133.129) {
                    var87 = -0.0676991;
                } else {
                    var87 = 0.05517151;
                }
            } else {
                if (input[67] < -23280.81) {
                    var87 = 0.04094922;
                } else {
                    var87 = -0.040855326;
                }
            }
        }
    }
    double var88;
    if (input[80] < -8557.976) {
        if (input[33] < -13295.037) {
            if (input[75] < -29920.082) {
                if (input[73] < 7173.4863) {
                    var88 = -0.03317162;
                } else {
                    var88 = -0.09231349;
                }
            } else {
                if (input[0] < -506.0893) {
                    var88 = -0.057420444;
                } else {
                    var88 = 0.055317283;
                }
            }
        } else {
            if (input[36] < -27564.203) {
                if (input[51] < 3962.655) {
                    var88 = -0.07145154;
                } else {
                    var88 = 0.03344725;
                }
            } else {
                if (input[99] < -21407.436) {
                    var88 = 0.021434797;
                } else {
                    var88 = 0.07564625;
                }
            }
        }
    } else {
        if (input[75] < -29920.486) {
            if (input[26] < -23714.549) {
                if (input[52] < -7986.3403) {
                    var88 = 0.044195335;
                } else {
                    var88 = -0.04756754;
                }
            } else {
                if (input[97] < -738.19977) {
                    var88 = 0.005344561;
                } else {
                    var88 = -0.081717394;
                }
            }
        } else {
            if (input[97] < 3762.348) {
                if (input[94] < -3320.3804) {
                    var88 = -0.08920908;
                } else {
                    var88 = -0.009803894;
                }
            } else {
                var88 = 0.0168941;
            }
        }
    }
    double var89;
    if (input[93] < -24460.432) {
        if (input[63] < 848.3366) {
            if (input[49] < -25999.297) {
                var89 = -0.08256252;
            } else {
                if (input[50] < 601.0712) {
                    var89 = -0.06386873;
                } else {
                    var89 = 0.013868736;
                }
            }
        } else {
            if (input[60] < 660.6071) {
                if (input[53] < -27137.125) {
                    var89 = 0.010964601;
                } else {
                    var89 = 0.0664301;
                }
            } else {
                var89 = -0.04439387;
            }
        }
    } else {
        if (input[2] < -19857.143) {
            if (input[6] < 5553.4087) {
                if (input[88] < 16600.846) {
                    var89 = -0.08108339;
                } else {
                    var89 = -0.0149779515;
                }
            } else {
                if (input[55] < -28291.83) {
                    var89 = -0.064842895;
                } else {
                    var89 = 0.012268685;
                }
            }
        } else {
            if (input[20] < -19405.297) {
                var89 = -0.06350446;
            } else {
                if (input[83] < -24566.93) {
                    var89 = -0.05273893;
                } else {
                    var89 = 0.04280416;
                }
            }
        }
    }
    double var90;
    if (input[3] < -28640.625) {
        if (input[51] < -2543.0154) {
            var90 = -0.07803976;
        } else {
            var90 = -0.00072249945;
        }
    } else {
        if (input[80] < -8557.976) {
            if (input[33] < -13295.037) {
                if (input[69] < -9052.219) {
                    var90 = -0.0892127;
                } else {
                    var90 = -0.0130192535;
                }
            } else {
                if (input[36] < -27564.203) {
                    var90 = -0.026414866;
                } else {
                    var90 = 0.06191179;
                }
            }
        } else {
            if (input[75] < -29920.486) {
                if (input[28] < -29984.834) {
                    var90 = -0.024794191;
                } else {
                    var90 = 0.027051747;
                }
            } else {
                if (input[97] < 3762.348) {
                    var90 = -0.06442167;
                } else {
                    var90 = 0.01778414;
                }
            }
        }
    }
    double var91;
    if (input[10] < 26730.783) {
        if (input[93] < -24415.834) {
            if (input[63] < 848.3366) {
                if (input[49] < -25999.297) {
                    var91 = -0.076275535;
                } else {
                    var91 = -0.016067427;
                }
            } else {
                if (input[60] < 660.6071) {
                    var91 = 0.054130234;
                } else {
                    var91 = -0.041275904;
                }
            }
        } else {
            if (input[21] < -12904.82) {
                if (input[83] < -24566.93) {
                    var91 = -0.05030792;
                } else {
                    var91 = 0.024694346;
                }
            } else {
                if (input[36] < -27363.953) {
                    var91 = -0.075554766;
                } else {
                    var91 = 0.03389693;
                }
            }
        }
    } else {
        var91 = -0.07167881;
    }
    double var92;
    if (input[31] < -1395.087) {
        if (input[57] < -28846.242) {
            if (input[89] < -24174.305) {
                if (input[6] < 7549.6265) {
                    var92 = 0.005582003;
                } else {
                    var92 = -0.08992848;
                }
            } else {
                if (input[94] < -17732.117) {
                    var92 = -0.05693386;
                } else {
                    var92 = 0.009229055;
                }
            }
        } else {
            if (input[94] < -2646.1611) {
                if (input[92] < -16177.651) {
                    var92 = -0.05240369;
                } else {
                    var92 = 0.038899653;
                }
            } else {
                if (input[74] < -21847.887) {
                    var92 = -0.07420254;
                } else {
                    var92 = 0.0203351;
                }
            }
        }
    } else {
        if (input[36] < -27099.463) {
            if (input[43] < -11758.921) {
                var92 = -0.08305707;
            } else {
                var92 = -0.0011659939;
            }
        } else {
            if (input[59] < -12462.128) {
                var92 = 0.039378148;
            } else {
                var92 = -0.02384851;
            }
        }
    }
    double var93;
    if (input[73] < 3176.7595) {
        if (input[97] < -27114.293) {
            var93 = 0.0075105987;
        } else {
            var93 = -0.07011612;
        }
    } else {
        if (input[73] < 7193.126) {
            if (input[75] < -29921.525) {
                if (input[25] < -15507.193) {
                    var93 = -0.037923206;
                } else {
                    var93 = 0.04602502;
                }
            } else {
                var93 = -0.06483755;
            }
        } else {
            if (input[2] < -19519.352) {
                if (input[6] < 22627.346) {
                    var93 = -0.04682324;
                } else {
                    var93 = 0.025743863;
                }
            } else {
                if (input[85] < 15572.329) {
                    var93 = 0.030995471;
                } else {
                    var93 = -0.046863656;
                }
            }
        }
    }
    double var94;
    if (input[1] < -26403.361) {
        if (input[87] < -14845.725) {
            var94 = -0.07177455;
        } else {
            var94 = 0.0067369738;
        }
    } else {
        if (input[55] < -28654.81) {
            if (input[63] < 694.4915) {
                var94 = -0.06952371;
            } else {
                var94 = 0.0075248927;
            }
        } else {
            if (input[96] < -2100.5803) {
                if (input[16] < -27803.775) {
                    var94 = -0.061725147;
                } else {
                    var94 = 0.028224442;
                }
            } else {
                if (input[21] < -11841.917) {
                    var94 = 0.017707296;
                } else {
                    var94 = -0.04191233;
                }
            }
        }
    }
    double var95;
    if (input[26] < -22309.15) {
        if (input[46] < -7005.7583) {
            if (input[78] < -23003.795) {
                if (input[89] < -20497.9) {
                    var95 = 0.032259103;
                } else {
                    var95 = -0.05031311;
                }
            } else {
                if (input[38] < 2436.2676) {
                    var95 = -0.08205715;
                } else {
                    var95 = -0.0029161915;
                }
            }
        } else {
            if (input[50] < 563.08386) {
                if (input[87] < -16623.207) {
                    var95 = -0.038244575;
                } else {
                    var95 = 0.027770955;
                }
            } else {
                if (input[94] < -2646.1611) {
                    var95 = 0.038663175;
                } else {
                    var95 = -0.03779363;
                }
            }
        }
    } else {
        if (input[97] < -4548.1616) {
            if (input[8] < -18859.492) {
                var95 = -0.058957536;
            } else {
                if (input[55] < -27630.393) {
                    var95 = -0.027785946;
                } else {
                    var95 = 0.042383622;
                }
            }
        } else {
            if (input[85] < -4826.4033) {
                var95 = -0.025694413;
            } else {
                var95 = -0.08860751;
            }
        }
    }
    double var96;
    if (input[4] < -28422.746) {
        if (input[85] < -25097.373) {
            var96 = 0.015313876;
        } else {
            if (input[19] < -5952.4077) {
                var96 = -0.08104699;
            } else {
                var96 = -0.007920563;
            }
        }
    } else {
        if (input[4] < -28101.55) {
            if (input[46] < -2219.8452) {
                var96 = -0.020925976;
            } else {
                if (input[2] < -20823.656) {
                    var96 = 0.008420207;
                } else {
                    var96 = 0.078144334;
                }
            }
        } else {
            if (input[38] < -5287.958) {
                if (input[59] < -13475.773) {
                    var96 = 0.03223833;
                } else {
                    var96 = -0.02142021;
                }
            } else {
                if (input[38] < 5639.2817) {
                    var96 = -0.035159912;
                } else {
                    var96 = 0.03227118;
                }
            }
        }
    }
    double var97;
    if (input[30] < -27825.465) {
        if (input[77] < -18755.139) {
            if (input[87] < -15257.741) {
                var97 = -0.08656395;
            } else {
                if (input[26] < -26748.516) {
                    var97 = 0.03581309;
                } else {
                    var97 = -0.033383485;
                }
            }
        } else {
            if (input[26] < -23833.54) {
                if (input[83] < -19467.986) {
                    var97 = 0.006860702;
                } else {
                    var97 = 0.069299735;
                }
            } else {
                var97 = -0.028380036;
            }
        }
    } else {
        if (input[81] < -10098.28) {
            if (input[65] < -12586.535) {
                var97 = -0.07054945;
            } else {
                if (input[24] < -2459.0164) {
                    var97 = -0.0365938;
                } else {
                    var97 = 0.03356177;
                }
            }
        } else {
            if (input[14] < 1379.3103) {
                if (input[8] < -14685.486) {
                    var97 = -0.07792185;
                } else {
                    var97 = 0.025824178;
                }
            } else {
                if (input[83] < -18525.396) {
                    var97 = 0.035813738;
                } else {
                    var97 = -0.055706795;
                }
            }
        }
    }
    double var98;
    if (input[15] < -19318.182) {
        if (input[13] < -12299.183) {
            if (input[91] < -28600.71) {
                var98 = -0.07430475;
            } else {
                var98 = -0.006259096;
            }
        } else {
            if (input[45] < -29221.906) {
                if (input[47] < -22753.107) {
                    var98 = -0.07065723;
                } else {
                    var98 = -0.014005201;
                }
            } else {
                if (input[7] < -29218.254) {
                    var98 = -0.02615118;
                } else {
                    var98 = 0.022571754;
                }
            }
        }
    } else {
        if (input[7] < -28068.293) {
            if (input[60] < 10217.681) {
                if (input[68] < -25752.127) {
                    var98 = -0.0002845542;
                } else {
                    var98 = -0.08843882;
                }
            } else {
                var98 = 0.018627666;
            }
        } else {
            if (input[25] < -10502.68) {
                var98 = -0.023038648;
            } else {
                var98 = 0.06061539;
            }
        }
    }
    double var99;
    if (input[31] < -1395.087) {
        if (input[11] < -26216.514) {
            var99 = -0.06370044;
        } else {
            if (input[41] < -14669.012) {
                if (input[81] < -10771.766) {
                    var99 = 0.002004137;
                } else {
                    var99 = -0.07479131;
                }
            } else {
                if (input[91] < -29227.15) {
                    var99 = -0.018651463;
                } else {
                    var99 = 0.027206678;
                }
            }
        }
    } else {
        if (input[36] < -27099.463) {
            if (input[43] < -11758.921) {
                var99 = -0.079020195;
            } else {
                var99 = -0.00020576552;
            }
        } else {
            var99 = 0.00992296;
        }
    }
    double var100;
    var100 = sigmoid(var0 + var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10 + var11 + var12 + var13 + var14 + var15 + var16 + var17 + var18 + var19 + var20 + var21 + var22 + var23 + var24 + var25 + var26 + var27 + var28 + var29 + var30 + var31 + var32 + var33 + var34 + var35 + var36 + var37 + var38 + var39 + var40 + var41 + var42 + var43 + var44 + var45 + var46 + var47 + var48 + var49 + var50 + var51 + var52 + var53 + var54 + var55 + var56 + var57 + var58 + var59 + var60 + var61 + var62 + var63 + var64 + var65 + var66 + var67 + var68 + var69 + var70 + var71 + var72 + var73 + var74 + var75 + var76 + var77 + var78 + var79 + var80 + var81 + var82 + var83 + var84 + var85 + var86 + var87 + var88 + var89 + var90 + var91 + var92 + var93 + var94 + var95 + var96 + var97 + var98 + var99);
    memcpy(output, (double[]){1.0 - var100, var100}, 2 * sizeof(double));
}


#endif // XGB_MODEL_H
