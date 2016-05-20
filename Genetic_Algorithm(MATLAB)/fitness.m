function [] = fitness( pop_size, chromo_size )
%fitness 计算种群个体适应度，对不同的优化目标，此处需要改写
%pop_size: 种群大小
%chromo_size: 染色体长度
global fitness_value;%种群的适应度
% global fitness_val;%适应度尺度变换
global pop;%当前代的种群基因

for i=1:pop_size
    fitness_value(i)=0.;
end

for i=1:pop_size
    
     for j=chromo_size-1:1
        pop(i,j)=xor(pop(i,j+1),pop(i,j)); %格雷码转二进制
     end
    
    for j=1:chromo_size
        if pop(i,j)==1
            fitness_value(i)=fitness_value(i)+2^(j-1);%二进制转化为十进制
        end
    end
    fitness_value(i)=0.+fitness_value(i)*(10.-0.)/(2^chromo_size-1);%转化为定义域中相应的数
    fitness_value(i)=fitness_value(i)+10.*sin(5.*fitness_value(i))+7.*cos(4.*fitness_value(i))+20.;
%     fitness_value(i)=fitness_value(i);
end
clear i;
clear j;

end

