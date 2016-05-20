function [] = plotGA( generation_size )
%plotGA 打印算法迭代过程
%generation_size: 迭代次数
global fitness_avg;
x=1:1:generation_size;
y=fitness_avg-20;
plot(x,y);
end

