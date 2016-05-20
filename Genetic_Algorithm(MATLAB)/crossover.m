function [] = crossover( pop_size,chromo_size,cross_rate )
%crossover 单点交叉操作
%pop_size: 种群大小
%chromo_size: 染色体长度
%cross_rate: 交叉概率
global pop;
for i=1:2:pop_size
    if(rand<cross_rate)
        cross_pos=round(rand*chromo_size);%随机选取交叉位置
        if or(cross_pos==0,cross_pos==1)
            continue;
        end
        for j=cross_pos:chromo_size
            temp=pop(i,j);
            pop(i,j)=pop(i+1,j);
            pop(i+1,j)=temp;
        end
    end
end
clear i;
clear j;
clear temp;
clear cross_pos;
end
