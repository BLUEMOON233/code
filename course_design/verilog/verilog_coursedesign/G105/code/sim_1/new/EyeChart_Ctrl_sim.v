`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/06/25 03:28:55
// Design Name: 
// Module Name: EyeChart_Ctrl_sim
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


module EyeChart_Ctrl_sim(
    );
    
    reg clk = 0;
    reg [3:0] btn = 4'h0;
    wire [1:0] sel;
    wire [1:0] rst;
    
    EyeChart_Control ec(
        .clk(clk),
        .btn(btn),
        .sel(sel),
        .rst(rst)
    );
    
    initial begin
        #0      clk = 1;
                btn = 4'b0000;
        #9      btn = 4'b0100;
        #4      btn = 4'b0000;
        #50     $finish;
    end
    always #1 clk = ~clk;
    
endmodule
