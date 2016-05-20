function [] = mutation( pop_size,chromo_size,mutate_rate )
%mutation 单点变异操作
%pop_size: 种群大小
%chromo_size: 染色体长度
%mutate_rate: 变异概率
global pop;
for i=1:pop_size
    if rand<mutate_rate
        mutate_pos=round(rand*chromo_size);%随机选取变异位置
        if mutate_pos==0
            continue;
        end
        pop(i,mutate_pos)=1-pop(i,mutate_pos);
    end
end

clear i;
clear mutate_pos;
end

