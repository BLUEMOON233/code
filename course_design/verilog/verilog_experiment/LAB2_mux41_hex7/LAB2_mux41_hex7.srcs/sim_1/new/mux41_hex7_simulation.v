`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/12 18:02:21
// Design Name: 
// Module Name: mux41_hex7_simulation
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


module mux41_hex7_simulation(
    );
    reg [15: 0] x;
    reg [3: 0] btn;
    wire [6: 0] seg;
    wire [3: 0] an;

    mux41_hex7 mh7(.x(x), .btn(btn), .seg(seg), .an(an));

    initial begin
        #0      x = 16'b0100001100100001;
                btn = 4'b0000;
        #100    x = 16'b0100001100100001;
                btn = 4'b0001;
        #100    x = 16'b0100001100100001;
                btn = 4'b0010;
        #100    x = 16'b0100001100100001;
                btn = 4'b0100;
        #100    x = 16'b0100001100100001;
                btn = 4'b1000;
        #100    x = 16'b0100001100100001;
                btn = 4'b1001;
        #100    $finish;
    end

endmodule
