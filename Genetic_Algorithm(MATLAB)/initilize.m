function [] = initilize( pop_size, chromo_size )
%initilize ��ʼ����Ⱥ
%pop_size: ��Ⱥ��С
%chromo_size: Ⱦɫ�峤��
global pop;%��ǰ������Ⱥ����
for i=1:pop_size
    for j=1:chromo_size
        pop(i,j)=round(rand);%�������0��1
    end
end
clear i;
clear j;    
end

