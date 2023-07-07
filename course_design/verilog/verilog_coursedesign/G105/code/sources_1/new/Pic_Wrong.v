`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/22 21:03:17
// Design Name: 
// Module Name: Pic_Wrong
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Pic_Wrong(
    input [9:0] in_x,
    input [9:0] in_y,
    output reg [11:0] pix_data
    );
    parameter 
    charline001=	128'h00000000000000000000000000000000,
    charline002=	128'h00000000000000000000000000000000,
    charline003=	128'h00000000000000000000000000000000,
    charline004=	128'h00000000000000000000000000000000,
    charline005=	128'h00000000000000000000000000000000,
    charline006=	128'h00000000000000000000000000000000,
    charline007=	128'h00000000000000000000000000000000,
    charline008=	128'h00000000000000000000000000000000,
    charline009=	128'h00000000000000000000000000000000,
    charline010=	128'h00000000000000000000000000000000,
    charline011=	128'h00000000000000000000000000000000,
    charline012=	128'h00000000000000000000000000000000,
    charline013=	128'h00000000000000000000000000000000,
    charline014=	128'h00000000000000000000000000000000,
    charline015=	128'h00000000000000000000000000000000,
    charline016=	128'h00000000000000000000000000000000,
    charline017=	128'h00000000000000000000000000000000,
    charline018=	128'h00000000000000000000000000000000,
    charline019=	128'h00000000000000000000000000000000,
    charline020=	128'h00000000000000000000000000000000,
    charline021=	128'h00000000000000000000000000000000,
    charline022=	128'h00000000000000000000000000000000,
    charline023=	128'h00000000000000000000000000000000,
    charline024=	128'h00000000000000000000000000000000,
    charline025=	128'h00000000000000000000000000000000,
    charline026=	128'h00000000000000000000000000000000,
    charline027=	128'h00000000000000000000000000000000,
    charline028=	128'h00000000000000000000000000000000,
    charline029=	128'h00000000000000000000000000000000,
    charline030=	128'h00000000000000000000000000000000,
    charline031=	128'h00000000000000000000000000000000,
    charline032=	128'h00000000000000000000000000000000,
    charline033=	128'h00000000000000000000000000000000,
    charline034=	128'h00000000000000000000000000000000,
    charline035=	128'h00000000000000000000000000000000,
    charline036=	128'h00000000000000000000000000000000,
    charline037=	128'h00000000000000000000000000000000,
    charline038=	128'h00000000000000000000000000000000,
    charline039=	128'h00000000000000000000000000000000,
    charline040=	128'h00000000000000000000000000000000,
    charline041=	128'h00000000000000000000000000000000,
    charline042=	128'h00000000000000000000000000000000,
    charline043=	128'h00000000000000000000000000000000,
    charline044=	128'h00000000000000000000000000000000,
    charline045=	128'h00000000000000000000000000000000,
    charline046=	128'h00000000000000000000000000000000,
    charline047=	128'h00000000000000000000000000000000,
    charline048=	128'h00000000000000000000000000000000,
    charline049=	128'h00000000000000000000000000000000,
    charline050=	128'h00000000000000000000000000000000,
    charline051=	128'h00000000000000000000000000000000,
    charline052=	128'h00000000000000000000000000000000,
    charline053=	128'h00000000000000000000000000000000,
    charline054=	128'h00000000000000000000000000000000,
    charline055=	128'h00000000000000000000000000000000,
    charline056=	128'h00000000000000000000000000000000,
    charline057=	128'h00000000000000000000000000000000,
    charline058=	128'h00000000000000000000000000000000,
    charline059=	128'h00000000000000000000000000000000,
    charline060=	128'h00000000000000000000000000000000,
    charline061=	128'h00000000000000000000000000000000,
    charline062=	128'h00000000000000000000000000000000,
    charline063=	128'h00000000000000000000000000000000,
    charline064=	128'h00000000000000000000000000000000,
    charline065=	128'h00000000000000000000000000000000,
    charline066=	128'h00000000000000000000000000000000,
    charline067=	128'h00000000000000000000000000000000,
    charline068=	128'h00000000000000000000000000000000,
    charline069=	128'h00000000000000000000000000000000,
    charline070=	128'h00000000000000000000000000000000,
    charline071=	128'h00000000000000000000000000000000,
    charline072=	128'h00000000000000000000000000000000,
    charline073=	128'h000000000000700000007F0000FE0000,
    charline074=	128'h00000000000000000000000000000000,
    charline075=	128'h0000000000007F0000007F8000FF0000,
    charline076=	128'h00000000000000000000000000000000,
    charline077=	128'h000000000000FF8000007F8000FF0000,
    charline078=	128'h00000000000000000000000000000000,
    charline079=	128'h000000000000FF8000007F8000FF0000,
    charline080=	128'h00380000000000000000000000000000,
    charline081=	128'h000000000000FF0000007F8000FF0000,
    charline082=	128'h007C0000FFFFFFFFFFFFE00000000000,
    charline083=	128'h000000000000FF0000007F8000FF0000,
    charline084=	128'h00FE0000FFFFFFFFFFFFE00000000000,
    charline085=	128'h000000000001FF0000007F8000FF0000,
    charline086=	128'h01FF0000FFFFFFFFFFFFE00000000000,
    charline087=	128'h000000000001FE0000007F8000FF0000,
    charline088=	128'h03FF8000FFFFFFFFFFFFE00000000000,
    charline089=	128'h000000000001FE0000007F8000FF0000,
    charline090=	128'h01FFC000FFFFFFFFFFFFE00000000000,
    charline091=	128'h000000000001FE0000007F8000FF0000,
    charline092=	128'h01FFE000FFFFFFFFFFFFE00000000000,
    charline093=	128'h000000000003FE0000007F8000FF0000,
    charline094=	128'h00FFF000FFFFFFFFFFFFE00000000000,
    charline095=	128'h000000000003FC0000007F8000FF0000,
    charline096=	128'h007FF800FF800000003FE00000000000,
    charline097=	128'h000000000003FC0000007F8000FF0000,
    charline098=	128'h003FFC00FF800000003FE00000000000,
    charline099=	128'h000000000007FC0003FFFFFFFFFFFFF0,
    charline100=	128'h001FFE00FF800000003FE00000000000,
    charline101=	128'h000000000007FFFFFBFFFFFFFFFFFFF0,
    charline102=	128'h000FFF00FF800000003FE00000000000,
    charline103=	128'h000000000007FFFFFBFFFFFFFFFFFFF0,
    charline104=	128'h0007FF00FF800000003FE00000000000,
    charline105=	128'h00000000000FFFFFFBFFFFFFFFFFFFF0,
    charline106=	128'h0007FF80FF800000003FE00000000000,
    charline107=	128'h00000000000FFFFFFBFFFFFFFFFFFFF0,
    charline108=	128'h0003FF00FF800000003FE00000000000,
    charline109=	128'h00000000001FFFFFFBFFFFFFFFFFFFF0,
    charline110=	128'h0001FE00FF800000003FE00000000000,
    charline111=	128'h00000000001FFFFFFBFFFFFFFFFFFFF0,
    charline112=	128'h0000FC00FF800000003FE00000000000,
    charline113=	128'h00000000001FFFFFF0007F8000FF0000,
    charline114=	128'h00007800FF800000003FE00000000000,
    charline115=	128'h00000000003FE00000007F8000FF0000,
    charline116=	128'h00002000FF800000003FE00000000000,
    charline117=	128'h00000000003FC00000007F8000FF0000,
    charline118=	128'h00000000FF800000003FE00000000000,
    charline119=	128'h00000000007FC00000007F8000FF0000,
    charline120=	128'h00000000FFFFFFFFFFFFE00000000000,
    charline121=	128'h00000000007F800000007F8000FF0000,
    charline122=	128'h00000000FFFFFFFFFFFFE00000000000,
    charline123=	128'h0000000000FF800000007F8000FF0000,
    charline124=	128'h00000000FFFFFFFFFFFFE00000000000,
    charline125=	128'h0000000000FF800000007F8000FF0000,
    charline126=	128'h00000000FFFFFFFFFFFFE00000000000,
    charline127=	128'h0000000001FF000000007F8000FF0000,
    charline128=	128'h00000000FFFFFFFFFFFFE00000000000,
    charline129=	128'h0000000001FF000000007F8000FF0000,
    charline130=	128'h00000000FFFFFFFFFFFFE00000000000,
    charline131=	128'h0000000003FE000000007F8000FF0000,
    charline132=	128'h00000000FFFFFFFFFFFFE00000000000,
    charline133=	128'h0000000003FFFFFFC0007F8000FF0000,
    charline134=	128'h00000000FF800000003FE00000000000,
    charline135=	128'h0000000003FFFFFFCFFFFFFFFFFFFFFE,
    charline136=	128'h7FFFF000FF800000003FE00000000000,
    charline137=	128'h0000000003FFFFFFCFFFFFFFFFFFFFFE,
    charline138=	128'h7FFFF000FF800000003FE00000000000,
    charline139=	128'h0000000001FFFFFFCFFFFFFFFFFFFFFE,
    charline140=	128'h7FFFF000FF000000003FC00000000000,
    charline141=	128'h0000000001F7FFFFCFFFFFFFFFFFFFFE,
    charline142=	128'h7FFFF000000000000000000000000000,
    charline143=	128'h0000000000F7FFFFCFFFFFFFFFFFFFFE,
    charline144=	128'h7FFFF000000000000000000000000000,
    charline145=	128'h0000000000E7FFFFCFFFFFFFFFFFFFFE,
    charline146=	128'h7FFFF000000000000000000000000000,
    charline147=	128'h0000000000607F800FFFFFFFFFFFFFFE,
    charline148=	128'h7FFFF000000000000000000000000000,
    charline149=	128'h0000000000007F800000000000000000,
    charline150=	128'h001FF00FFFFFFFFFFFFFFE0000000000,
    charline151=	128'h0000000000007F800000000000000000,
    charline152=	128'h001FF00FFFFFFFFFFFFFFE0000000000,
    charline153=	128'h0000000000007F800000000000000000,
    charline154=	128'h001FF00FFFFFFFFFFFFFFE0000000000,
    charline155=	128'h0000000000007F800000000000000000,
    charline156=	128'h001FF00FFFFFFFFFFFFFFE0000000000,
    charline157=	128'h0000000000007F800000000000000000,
    charline158=	128'h001FF00FFFFFFFFFFFFFFE0000000000,
    charline159=	128'h0000000000007F800000000000000000,
    charline160=	128'h001FF00FFFFFFFFFFFFFFE0000000000,
    charline161=	128'h0000000000007F800000000000000000,
    charline162=	128'h001FF00FFFFFFFFFFFFFFE0000000000,
    charline163=	128'h0000000000007F80003FFFFFFFFFFF00,
    charline164=	128'h001FF000000007F80000000000000000,
    charline165=	128'h0000000000007F80003FFFFFFFFFFF00,
    charline166=	128'h001FF000000007F80000000000000000,
    charline167=	128'h0000000003FFFFFFF03FFFFFFFFFFF00,
    charline168=	128'h001FF000000007F80000000000000000,
    charline169=	128'h0000000003FFFFFFF03FFFFFFFFFFF00,
    charline170=	128'h001FF000000007F80000000000000000,
    charline171=	128'h0000000003FFFFFFF03FFFFFFFFFFF00,
    charline172=	128'h001FF00000000FF80000000000000000,
    charline173=	128'h0000000003FFFFFFF03FFFFFFFFFFF00,
    charline174=	128'h001FF00000000FF80000000000000000,
    charline175=	128'h0000000003FFFFFFF03FC0000000FF00,
    charline176=	128'h001FF00000000FF80000000000000000,
    charline177=	128'h0000000003FFFFFFF03FC0000000FF00,
    charline178=	128'h001FF00000000FF80000000000000000,
    charline179=	128'h0000000003FFFFFFF03FC0000000FF00,
    charline180=	128'h001FF00000000FF80000000000000000,
    charline181=	128'h0000000000007F80003FC0000000FF00,
    charline182=	128'h001FF03FFFFFFFFFFFFFFF8000000000,
    charline183=	128'h0000000000007F80003FC0000000FF00,
    charline184=	128'h001FF07FFFFFFFFFFFFFFFC000000000,
    charline185=	128'h0000000000007F80003FC0000000FF00,
    charline186=	128'h001FF07FFFFFFFFFFFFFFFC000000000,
    charline187=	128'h0000000000007F80003FC0000000FF00,
    charline188=	128'h001FF07FFFFFFFFFFFFFFFC000000000,
    charline189=	128'h0000000000007F80003FC0000000FF00,
    charline190=	128'h001FF07FFFFFFFFFFFFFFFC000000000,
    charline191=	128'h0000000000007F80003FC0000000FF00,
    charline192=	128'h001FF07FFFFFFFFFFFFFFFC000000000,
    charline193=	128'h0000000000007F80003FC0000000FF00,
    charline194=	128'h001FF07FFFFFFFFFFFFFFFC000000000,
    charline195=	128'h0000000000007F80003FFFFFFFFFFF00,
    charline196=	128'h001FF03FFFFFFFFFFFFFFF8000000000,
    charline197=	128'h0000000000007F80003FFFFFFFFFFF00,
    charline198=	128'h001FF00000003FFE0000000000000000,
    charline199=	128'h0000000000007F80003FFFFFFFFFFF00,
    charline200=	128'h001FF00000007FFF0000000000000000,
    charline201=	128'h0000000000007F80603FFFFFFFFFFF00,
    charline202=	128'h001FF00000007FFF8000000000000000,
    charline203=	128'h0000000000007F80F03FFFFFFFFFFF00,
    charline204=	128'h001FF01C0000FFFF8000000000000000,
    charline205=	128'h0000000000007F81F03FFFFFFFFFFF00,
    charline206=	128'h001FF03C0001FF7FC000000000000000,
    charline207=	128'h0000000000007F83F03FC0000000FF00,
    charline208=	128'h001FF0FC0001FF3FE000000000000000,
    charline209=	128'h0000000000007F87F03FC0000000FF00,
    charline210=	128'h001FF1FC0003FE3FF000000000000000,
    charline211=	128'h0000000000007F8FF83FC0000000FF00,
    charline212=	128'h001FF7FC0007FE1FF800000000000000,
    charline213=	128'h0000000000007F9FF83FC0000000FF00,
    charline214=	128'h001FFFFC000FFC1FFC00000000000000,
    charline215=	128'h0000000000007FBFF03FC0000000FF00,
    charline216=	128'h001FFFFC001FF80FFE00000000000000,
    charline217=	128'h0000000000007FFFE03FC0000000FF00,
    charline218=	128'h001FFFFC003FF807FF00000000000000,
    charline219=	128'h0000000000007FFFC03FC0000000FF00,
    charline220=	128'h001FFFF800FFF003FF80000000000000,
    charline221=	128'h0000000000007FFF803FC0000000FF00,
    charline222=	128'h001FFFF001FFE001FFE0000000000000,
    charline223=	128'h0000000000007FFF003FC0000000FF00,
    charline224=	128'h003FFFC007FFC001FFF8000000000000,
    charline225=	128'h0000000000007FFE003FC0000000FF00,
    charline226=	128'h003FFF800FFF8000FFFC000000000000,
    charline227=	128'h0000000000007FFC003FFFFFFFFFFF00,
    charline228=	128'h007FFE003FFF00007FFF000000000000,
    charline229=	128'h000000000000FFF8003FFFFFFFFFFF00,
    charline230=	128'h00FFFC00FFFE00003FFFE00000000000,
    charline231=	128'h000000000000FFF0003FFFFFFFFFFF00,
    charline232=	128'h007FF007FFF800000FFFFC0000000000,
    charline233=	128'h000000000001FFE0003FFFFFFFFFFF00,
    charline234=	128'h003FE01FFFF0000007FFFFC000000000,
    charline235=	128'h000000000001FFC0003FFFFFFFFFFF00,
    charline236=	128'h003FC0FFFFE0000003FFFFE000000000,
    charline237=	128'h000000000000FF80003FFFFFFFFFFF00,
    charline238=	128'h001F01FFFF80000000FFFFC000000000,
    charline239=	128'h0000000000007F00003FC0000000FF00,
    charline240=	128'h000E00FFFE000000007FFF8000000000,
    charline241=	128'h0000000000003E00003FC0000000FF00,
    charline242=	128'h000000FFF8000000001FFF0000000000,
    charline243=	128'h0000000000003C00003FC0000000FF00,
    charline244=	128'h0000007FE00000000007FF0000000000,
    charline245=	128'h0000000000001800003FC0000000FF00,
    charline246=	128'h0000003F800000000000FE0000000000,
    charline247=	128'h0000000000000000003FC0000000FF00,
    charline248=	128'h0000001E0000000000001C0000000000,
    charline249=	128'h00000000000000000000000000000000,
    charline250=	128'h00000000000000000000000000000000,
    charline251=	128'h00000000000000000000000000000000,
    charline252=	128'h00000000000000000000000000000000,
    charline253=	128'h00000000000000000000000000000000,
    charline254=	128'h00000000000000000000000000000000,
    charline255=	128'h00000000000000000000000000000000,
    charline256=	128'h00000000000000000000000000000000;
    wire [9:0] x;
    wire [9:0] y;
    assign x = (in_x >= 192 && in_x <= 447)?(255-(in_x-192)):639;
    assign y = (in_y >= 176 && in_y <= 303)?(in_y-176):479;
    
    always @(*) begin
        case(y)
            10'd0:
            if(x < 128 && charline002[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline001[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd1:
            if(x < 128 && charline004[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline003[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd2:
            if(x < 128 && charline006[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline005[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd3:
            if(x < 128 && charline008[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline007[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd4:
            if(x < 128 && charline010[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline009[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd5:
            if(x < 128 && charline012[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline011[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd6:
            if(x < 128 && charline014[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline013[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd7:
            if(x < 128 && charline016[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline015[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd8:
            if(x < 128 && charline018[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline017[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd9:
            if(x < 128 && charline020[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline019[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd10:
            if(x < 128 && charline022[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline021[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd11:
            if(x < 128 && charline024[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline023[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd12:
            if(x < 128 && charline026[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline025[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd13:
            if(x < 128 && charline028[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline027[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd14:
            if(x < 128 && charline030[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline029[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd15:
            if(x < 128 && charline032[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline031[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd16:
            if(x < 128 && charline034[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline033[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd17:
            if(x < 128 && charline036[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline035[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd18:
            if(x < 128 && charline038[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline037[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd19:
            if(x < 128 && charline040[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline039[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd20:
            if(x < 128 && charline042[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline041[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd21:
            if(x < 128 && charline044[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline043[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd22:
            if(x < 128 && charline046[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline045[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd23:
            if(x < 128 && charline048[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline047[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd24:
            if(x < 128 && charline050[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline049[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd25:
            if(x < 128 && charline052[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline051[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd26:
            if(x < 128 && charline054[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline053[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd27:
            if(x < 128 && charline056[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline055[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd28:
            if(x < 128 && charline058[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline057[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd29:
            if(x < 128 && charline060[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline059[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd30:
            if(x < 128 && charline062[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline061[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd31:
            if(x < 128 && charline064[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline063[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd32:
            if(x < 128 && charline066[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline065[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd33:
            if(x < 128 && charline068[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline067[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd34:
            if(x < 128 && charline070[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline069[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd35:
            if(x < 128 && charline072[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline071[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd36:
            if(x < 128 && charline074[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline073[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd37:
            if(x < 128 && charline076[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline075[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd38:
            if(x < 128 && charline078[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline077[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd39:
            if(x < 128 && charline080[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline079[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd40:
            if(x < 128 && charline082[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline081[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd41:
            if(x < 128 && charline084[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline083[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd42:
            if(x < 128 && charline086[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline085[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd43:
            if(x < 128 && charline088[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline087[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd44:
            if(x < 128 && charline090[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline089[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd45:
            if(x < 128 && charline092[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline091[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd46:
            if(x < 128 && charline094[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline093[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd47:
            if(x < 128 && charline096[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline095[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd48:
            if(x < 128 && charline098[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline097[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd49:
            if(x < 128 && charline100[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline099[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd50:
            if(x < 128 && charline102[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline101[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd51:
            if(x < 128 && charline104[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline103[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd52:
            if(x < 128 && charline106[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline105[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd53:
            if(x < 128 && charline108[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline107[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd54:
            if(x < 128 && charline110[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline109[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd55:
            if(x < 128 && charline112[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline111[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd56:
            if(x < 128 && charline114[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline113[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd57:
            if(x < 128 && charline116[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline115[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd58:
            if(x < 128 && charline118[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline117[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd59:
            if(x < 128 && charline120[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline119[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd60:
            if(x < 128 && charline122[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline121[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd61:
            if(x < 128 && charline124[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline123[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd62:
            if(x < 128 && charline126[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline125[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd63:
            if(x < 128 && charline128[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline127[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd64:
            if(x < 128 && charline130[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline129[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd65:
            if(x < 128 && charline132[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline131[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd66:
            if(x < 128 && charline134[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline133[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd67:
            if(x < 128 && charline136[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline135[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd68:
            if(x < 128 && charline138[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline137[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd69:
            if(x < 128 && charline140[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline139[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd70:
            if(x < 128 && charline142[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline141[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd71:
            if(x < 128 && charline144[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline143[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd72:
            if(x < 128 && charline146[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline145[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd73:
            if(x < 128 && charline148[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline147[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd74:
            if(x < 128 && charline150[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline149[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd75:
            if(x < 128 && charline152[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline151[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd76:
            if(x < 128 && charline154[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline153[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd77:
            if(x < 128 && charline156[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline155[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd78:
            if(x < 128 && charline158[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline157[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd79:
            if(x < 128 && charline160[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline159[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd80:
            if(x < 128 && charline162[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline161[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd81:
            if(x < 128 && charline164[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline163[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd82:
            if(x < 128 && charline166[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline165[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd83:
            if(x < 128 && charline168[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline167[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd84:
            if(x < 128 && charline170[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline169[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd85:
            if(x < 128 && charline172[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline171[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd86:
            if(x < 128 && charline174[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline173[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd87:
            if(x < 128 && charline176[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline175[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd88:
            if(x < 128 && charline178[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline177[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd89:
            if(x < 128 && charline180[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline179[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd90:
            if(x < 128 && charline182[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline181[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd91:
            if(x < 128 && charline184[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline183[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd92:
            if(x < 128 && charline186[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline185[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd93:
            if(x < 128 && charline188[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline187[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd94:
            if(x < 128 && charline190[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline189[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd95:
            if(x < 128 && charline192[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline191[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd96:
            if(x < 128 && charline194[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline193[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd97:
            if(x < 128 && charline196[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline195[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd98:
            if(x < 128 && charline198[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline197[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd99:
            if(x < 128 && charline200[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline199[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd100:
            if(x < 128 && charline202[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline201[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd101:
            if(x < 128 && charline204[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline203[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd102:
            if(x < 128 && charline206[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline205[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd103:
            if(x < 128 && charline208[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline207[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd104:
            if(x < 128 && charline210[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline209[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd105:
            if(x < 128 && charline212[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline211[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd106:
            if(x < 128 && charline214[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline213[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd107:
            if(x < 128 && charline216[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline215[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd108:
            if(x < 128 && charline218[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline217[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd109:
            if(x < 128 && charline220[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline219[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd110:
            if(x < 128 && charline222[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline221[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd111:
            if(x < 128 && charline224[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline223[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd112:
            if(x < 128 && charline226[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline225[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd113:
            if(x < 128 && charline228[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline227[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd114:
            if(x < 128 && charline230[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline229[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd115:
            if(x < 128 && charline232[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline231[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd116:
            if(x < 128 && charline234[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline233[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd117:
            if(x < 128 && charline236[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline235[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd118:
            if(x < 128 && charline238[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline237[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd119:
            if(x < 128 && charline240[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline239[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd120:
            if(x < 128 && charline242[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline241[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd121:
            if(x < 128 && charline244[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline243[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd122:
            if(x < 128 && charline246[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline245[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd123:
            if(x < 128 && charline248[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline247[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd124:
            if(x < 128 && charline250[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline249[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd125:
            if(x < 128 && charline252[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline251[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd126:
            if(x < 128 && charline254[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline253[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            10'd127:
            if(x < 128 && charline256[x]) pix_data = 12'hf00;
            else if(x >= 128 && charline255[x-128]) pix_data = 12'hf00;
            else pix_data = 12'hfff;
            default pix_data = 12'hfff;
        endcase
    end
endmodule
