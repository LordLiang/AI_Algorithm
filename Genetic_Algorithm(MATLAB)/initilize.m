function [] = initilize( pop_size, chromo_size )
%initilize 初始化种群
%pop_size: 种群大小
%chromo_size: 染色体长度
global pop;%当前代的种群基因
for i=1:pop_size
    for j=1:chromo_size
        pop(i,j)=round(rand);%随机生成0和1
    end
end
clear i;
clear j;    
end

