`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/22 22:14:01
// Design Name: 
// Module Name: Vision2Seg
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


module Vision2Seg(
    input clk,
    input sel_vis,
    input [2:0] vision,
    output reg [6:0] seg,
    output reg [3:0] an,
    output reg dp
    );
    reg [3:0] d0;
    reg [3:0] d1;
    reg [3:0] d2;
    reg [3:0] d3;
    reg [3:0] D;
    reg [17: 0] clk_reg = 0;
    wire [1:0] sel;
    always @(posedge clk) begin
        clk_reg <= clk_reg + 1;
    end
    assign sel = clk_reg[17:16];
    
    always @(*) begin
        case(vision)
            3'd0:begin
                if(sel_vis == 0) begin
                    d0 = 4'd0;
                    d1 = 4'd1;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd0;
                    d1 = 4'd4;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
            3'd1:begin
                if(sel_vis == 0) begin
                    d0 = 4'd5;
                    d1 = 4'd1;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd2;
                    d1 = 4'd4;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
            3'd2:begin
                if(sel_vis == 0) begin
                    d0 = 4'd0;
                    d1 = 4'd2;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd3;
                    d1 = 4'd4;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
            3'd3:begin
                if(sel_vis == 0) begin
                    d0 = 4'd0;
                    d1 = 4'd4;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd6;
                    d1 = 4'd4;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
            3'd4:begin
                if(sel_vis == 0) begin
                    d0 = 4'd0;
                    d1 = 4'd8;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd9;
                    d1 = 4'd4;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
            3'd5:begin
                if(sel_vis == 0) begin
                    d0 = 4'd0;
                    d1 = 4'd0;
                    d2 = 4'd1;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd0;
                    d1 = 4'd5;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
            3'd6:begin
                if(sel_vis == 0) begin
                    d0 = 4'd0;
                    d1 = 4'd5;
                    d2 = 4'd1;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd2;
                    d1 = 4'd5;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
            3'd7:begin
                if(sel_vis == 0) begin
                    d0 = 4'd0;
                    d1 = 4'd0;
                    d2 = 4'd2;
                    d3 = 4'd0;
                end else begin
                    d0 = 4'd3;
                    d1 = 4'd5;
                    d2 = 4'd0;
                    d3 = 4'd0;
                end
            end
        endcase
    end
    
    always @(*) begin
        if(sel_vis == 0) begin
            case (sel)
                2'b00: an = 4'b1110;
                2'b01: an = 4'b1101;
                2'b10: an = 4'b1011;
                2'b11: an = 4'b1111;
            endcase
        end else begin
            case (sel)
                2'b00: an = 4'b1110;
                2'b01: an = 4'b1101;
                2'b10: an = 4'b1111;
                2'b11: an = 4'b1111;
            endcase
        end
    end
    
    always @(*) begin
        case (sel)
            2'b00: D = d0;
            2'b01: D = d1;
            2'b10: D = d2;
            2'b11: D = d3;
        endcase
    end

    always @(*) begin
        if(sel_vis == 0) begin
            case (sel)
                2'b00: dp = 1;
                2'b01: dp = 1;
                2'b10: dp = 0;
                2'b11: dp = 1;
            endcase
        end else begin
            case (sel)
                2'b00: dp = 1;
                2'b01: dp = 0;
                2'b10: dp = 1;
                2'b11: dp = 1;
            endcase
        end
    end

    always @(*) begin
        case(D)
            0:  seg = 7'b0000001;
            1:  seg = 7'b1001111;
            2:  seg = 7'b0010010;
            3:  seg = 7'b0000110;
            4:  seg = 7'b1001100;
            5:  seg = 7'b0100100;
            6:  seg = 7'b0100000;
            7:  seg = 7'b0001111;
            8:  seg = 7'b0000000;
            9:  seg = 7'b0000100;
            10: seg = 7'b0001000;
            11: seg = 7'b1100000;
            12: seg = 7'b0110001;
            13: seg = 7'b1000010;
            14: seg = 7'b0110000;
            15: seg = 7'b0111000;
        endcase
    end
endmodule
